/* packet-wmx.c
 * WiMax Protocol and dissectors
 *
 * Copyright (c) 2007 by Intel Corporation.
 *
 * Author: Lu Pan <lu.pan@intel.com>
 *
 * $Id$
 *
 * Wireshark - Network traffic analyzer
 * By Gerald Combs <gerald@wireshark.org>
 * Copyright 1999 Gerald Combs
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

/* Include files */

#include "config.h"

#include <string.h>
#include <glib.h>
#include <epan/packet.h>
#include <epan/prefs.h>
#include <epan/address.h>
#include <epan/wmem/wmem.h>
#include "wimax_tlv.h"
#include "wimax_bits.h"

/* Global functions */
/* void proto_reg_handoff_wimax(void); */
gboolean is_down_link(packet_info *pinfo);

/* Global variables */
gint    proto_wimax = -1;
gint8   arq_enabled = 0;
gint    scheduling_service_type = 0;
gint    mac_sdu_length = 49; /* default SDU size is 49 bytes (11.13.16) */
extern	guint global_cid_max_basic;
extern	gboolean include_cor2_changes;

address bs_address = {AT_NONE, -1, 0, NULL};


static int hf_tlv_type = -1;
static int hf_tlv_length = -1;
static int hf_tlv_length_size = -1;

/* The following variables are local to the function, but serve as
   elements for the global ett_tlv[] array */
static gint ett_tlv_0 = -1;
static gint ett_tlv_1 = -1;
static gint ett_tlv_2 = -1;
static gint ett_tlv_3 = -1;
static gint ett_tlv_4 = -1;
static gint ett_tlv_5 = -1;
static gint ett_tlv_6 = -1;
static gint ett_tlv_7 = -1;
static gint ett_tlv_8 = -1;
static gint ett_tlv_9 = -1;
static gint ett_tlv_10 = -1;
static gint ett_tlv_11 = -1;
static gint ett_tlv_12 = -1;
static gint ett_tlv_13 = -1;
static gint ett_tlv_14 = -1;
static gint ett_tlv_15 = -1;
static gint ett_tlv_16 = -1;
static gint ett_tlv_17 = -1;
static gint ett_tlv_18 = -1;
static gint ett_tlv_19 = -1;
static gint ett_tlv_20 = -1;
static gint ett_tlv_21 = -1;
static gint ett_tlv_22 = -1;
static gint ett_tlv_23 = -1;
static gint ett_tlv_24 = -1;
static gint ett_tlv_25 = -1;
static gint ett_tlv_26 = -1;
static gint ett_tlv_27 = -1;
static gint ett_tlv_28 = -1;
static gint ett_tlv_29 = -1;
static gint ett_tlv_30 = -1;
static gint ett_tlv_31 = -1;
static gint ett_tlv_32 = -1;
static gint ett_tlv_33 = -1;
static gint ett_tlv_34 = -1;
static gint ett_tlv_35 = -1;
static gint ett_tlv_36 = -1;
static gint ett_tlv_37 = -1;
static gint ett_tlv_38 = -1;
static gint ett_tlv_39 = -1;
static gint ett_tlv_40 = -1;
static gint ett_tlv_41 = -1;
static gint ett_tlv_42 = -1;
static gint ett_tlv_43 = -1;
static gint ett_tlv_44 = -1;
static gint ett_tlv_45 = -1;
static gint ett_tlv_46 = -1;
static gint ett_tlv_47 = -1;
static gint ett_tlv_48 = -1;
static gint ett_tlv_49 = -1;
static gint ett_tlv_50 = -1;
static gint ett_tlv_51 = -1;
static gint ett_tlv_52 = -1;
static gint ett_tlv_53 = -1;
static gint ett_tlv_54 = -1;
static gint ett_tlv_55 = -1;
static gint ett_tlv_56 = -1;
static gint ett_tlv_57 = -1;
static gint ett_tlv_58 = -1;
static gint ett_tlv_59 = -1;
static gint ett_tlv_60 = -1;
static gint ett_tlv_61 = -1;
static gint ett_tlv_62 = -1;
static gint ett_tlv_63 = -1;
static gint ett_tlv_64 = -1;
static gint ett_tlv_65 = -1;
static gint ett_tlv_66 = -1;
static gint ett_tlv_67 = -1;
static gint ett_tlv_68 = -1;
static gint ett_tlv_69 = -1;
static gint ett_tlv_70 = -1;
static gint ett_tlv_71 = -1;
static gint ett_tlv_72 = -1;
static gint ett_tlv_73 = -1;
static gint ett_tlv_74 = -1;
static gint ett_tlv_75 = -1;
static gint ett_tlv_76 = -1;
static gint ett_tlv_77 = -1;
static gint ett_tlv_78 = -1;
static gint ett_tlv_79 = -1;
static gint ett_tlv_80 = -1;
static gint ett_tlv_81 = -1;
static gint ett_tlv_82 = -1;
static gint ett_tlv_83 = -1;
static gint ett_tlv_84 = -1;
static gint ett_tlv_85 = -1;
static gint ett_tlv_86 = -1;
static gint ett_tlv_87 = -1;
static gint ett_tlv_88 = -1;
static gint ett_tlv_89 = -1;
static gint ett_tlv_90 = -1;
static gint ett_tlv_91 = -1;
static gint ett_tlv_92 = -1;
static gint ett_tlv_93 = -1;
static gint ett_tlv_94 = -1;
static gint ett_tlv_95 = -1;
static gint ett_tlv_96 = -1;
static gint ett_tlv_97 = -1;
static gint ett_tlv_98 = -1;
static gint ett_tlv_99 = -1;
static gint ett_tlv_100 = -1;
static gint ett_tlv_101 = -1;
static gint ett_tlv_102 = -1;
static gint ett_tlv_103 = -1;
static gint ett_tlv_104 = -1;
static gint ett_tlv_105 = -1;
static gint ett_tlv_106 = -1;
static gint ett_tlv_107 = -1;
static gint ett_tlv_108 = -1;
static gint ett_tlv_109 = -1;
static gint ett_tlv_110 = -1;
static gint ett_tlv_111 = -1;
static gint ett_tlv_112 = -1;
static gint ett_tlv_113 = -1;
static gint ett_tlv_114 = -1;
static gint ett_tlv_115 = -1;
static gint ett_tlv_116 = -1;
static gint ett_tlv_117 = -1;
static gint ett_tlv_118 = -1;
static gint ett_tlv_119 = -1;
static gint ett_tlv_120 = -1;
static gint ett_tlv_121 = -1;
static gint ett_tlv_122 = -1;
static gint ett_tlv_123 = -1;
static gint ett_tlv_124 = -1;
static gint ett_tlv_125 = -1;
static gint ett_tlv_126 = -1;
static gint ett_tlv_127 = -1;
static gint ett_tlv_128 = -1;
static gint ett_tlv_129 = -1;
static gint ett_tlv_130 = -1;
static gint ett_tlv_131 = -1;
static gint ett_tlv_132 = -1;
static gint ett_tlv_133 = -1;
static gint ett_tlv_134 = -1;
static gint ett_tlv_135 = -1;
static gint ett_tlv_136 = -1;
static gint ett_tlv_137 = -1;
static gint ett_tlv_138 = -1;
static gint ett_tlv_139 = -1;
static gint ett_tlv_140 = -1;
static gint ett_tlv_141 = -1;
static gint ett_tlv_142 = -1;
static gint ett_tlv_143 = -1;
static gint ett_tlv_144 = -1;
static gint ett_tlv_145 = -1;
static gint ett_tlv_146 = -1;
static gint ett_tlv_147 = -1;
static gint ett_tlv_148 = -1;
static gint ett_tlv_149 = -1;
static gint ett_tlv_150 = -1;
static gint ett_tlv_151 = -1;
static gint ett_tlv_152 = -1;
static gint ett_tlv_153 = -1;
static gint ett_tlv_154 = -1;
static gint ett_tlv_155 = -1;
static gint ett_tlv_156 = -1;
static gint ett_tlv_157 = -1;
static gint ett_tlv_158 = -1;
static gint ett_tlv_159 = -1;
static gint ett_tlv_160 = -1;
static gint ett_tlv_161 = -1;
static gint ett_tlv_162 = -1;
static gint ett_tlv_163 = -1;
static gint ett_tlv_164 = -1;
static gint ett_tlv_165 = -1;
static gint ett_tlv_166 = -1;
static gint ett_tlv_167 = -1;
static gint ett_tlv_168 = -1;
static gint ett_tlv_169 = -1;
static gint ett_tlv_170 = -1;
static gint ett_tlv_171 = -1;
static gint ett_tlv_172 = -1;
static gint ett_tlv_173 = -1;
static gint ett_tlv_174 = -1;
static gint ett_tlv_175 = -1;
static gint ett_tlv_176 = -1;
static gint ett_tlv_177 = -1;
static gint ett_tlv_178 = -1;
static gint ett_tlv_179 = -1;
static gint ett_tlv_180 = -1;
static gint ett_tlv_181 = -1;
static gint ett_tlv_182 = -1;
static gint ett_tlv_183 = -1;
static gint ett_tlv_184 = -1;
static gint ett_tlv_185 = -1;
static gint ett_tlv_186 = -1;
static gint ett_tlv_187 = -1;
static gint ett_tlv_188 = -1;
static gint ett_tlv_189 = -1;
static gint ett_tlv_190 = -1;
static gint ett_tlv_191 = -1;
static gint ett_tlv_192 = -1;
static gint ett_tlv_193 = -1;
static gint ett_tlv_194 = -1;
static gint ett_tlv_195 = -1;
static gint ett_tlv_196 = -1;
static gint ett_tlv_197 = -1;
static gint ett_tlv_198 = -1;
static gint ett_tlv_199 = -1;
static gint ett_tlv_200 = -1;
static gint ett_tlv_201 = -1;
static gint ett_tlv_202 = -1;
static gint ett_tlv_203 = -1;
static gint ett_tlv_204 = -1;
static gint ett_tlv_205 = -1;
static gint ett_tlv_206 = -1;
static gint ett_tlv_207 = -1;
static gint ett_tlv_208 = -1;
static gint ett_tlv_209 = -1;
static gint ett_tlv_210 = -1;
static gint ett_tlv_211 = -1;
static gint ett_tlv_212 = -1;
static gint ett_tlv_213 = -1;
static gint ett_tlv_214 = -1;
static gint ett_tlv_215 = -1;
static gint ett_tlv_216 = -1;
static gint ett_tlv_217 = -1;
static gint ett_tlv_218 = -1;
static gint ett_tlv_219 = -1;
static gint ett_tlv_220 = -1;
static gint ett_tlv_221 = -1;
static gint ett_tlv_222 = -1;
static gint ett_tlv_223 = -1;
static gint ett_tlv_224 = -1;
static gint ett_tlv_225 = -1;
static gint ett_tlv_226 = -1;
static gint ett_tlv_227 = -1;
static gint ett_tlv_228 = -1;
static gint ett_tlv_229 = -1;
static gint ett_tlv_230 = -1;
static gint ett_tlv_231 = -1;
static gint ett_tlv_232 = -1;
static gint ett_tlv_233 = -1;
static gint ett_tlv_234 = -1;
static gint ett_tlv_235 = -1;
static gint ett_tlv_236 = -1;
static gint ett_tlv_237 = -1;
static gint ett_tlv_238 = -1;
static gint ett_tlv_239 = -1;
static gint ett_tlv_240 = -1;
static gint ett_tlv_241 = -1;
static gint ett_tlv_242 = -1;
static gint ett_tlv_243 = -1;
static gint ett_tlv_244 = -1;
static gint ett_tlv_245 = -1;
static gint ett_tlv_246 = -1;
static gint ett_tlv_247 = -1;
static gint ett_tlv_248 = -1;
static gint ett_tlv_249 = -1;
static gint ett_tlv_250 = -1;
static gint ett_tlv_251 = -1;
static gint ett_tlv_252 = -1;
static gint ett_tlv_253 = -1;
static gint ett_tlv_254 = -1;
static gint ett_tlv_255 = -1;

/* Global TLV array to retrieve unique subtree identifiers */
/* Note: ett_tlv_0 is a placeholder so the TLV number will
      correlate directly with the index number */
gint *ett_tlv[] =
{
	&ett_tlv_0,
	&ett_tlv_1,
	&ett_tlv_2,
	&ett_tlv_3,
	&ett_tlv_4,
	&ett_tlv_5,
	&ett_tlv_6,
	&ett_tlv_7,
	&ett_tlv_8,
	&ett_tlv_9,
	&ett_tlv_10,
	&ett_tlv_11,
	&ett_tlv_12,
	&ett_tlv_13,
	&ett_tlv_14,
	&ett_tlv_15,
	&ett_tlv_16,
	&ett_tlv_17,
	&ett_tlv_18,
	&ett_tlv_19,
	&ett_tlv_20,
	&ett_tlv_21,
	&ett_tlv_22,
	&ett_tlv_23,
	&ett_tlv_24,
	&ett_tlv_25,
	&ett_tlv_26,
	&ett_tlv_27,
	&ett_tlv_28,
	&ett_tlv_29,
	&ett_tlv_30,
	&ett_tlv_31,
	&ett_tlv_32,
	&ett_tlv_33,
	&ett_tlv_34,
	&ett_tlv_35,
	&ett_tlv_36,
	&ett_tlv_37,
	&ett_tlv_38,
	&ett_tlv_39,
	&ett_tlv_40,
	&ett_tlv_41,
	&ett_tlv_42,
	&ett_tlv_43,
	&ett_tlv_44,
	&ett_tlv_45,
	&ett_tlv_46,
	&ett_tlv_47,
	&ett_tlv_48,
	&ett_tlv_49,
	&ett_tlv_50,
	&ett_tlv_51,
	&ett_tlv_52,
	&ett_tlv_53,
	&ett_tlv_54,
	&ett_tlv_55,
	&ett_tlv_56,
	&ett_tlv_57,
	&ett_tlv_58,
	&ett_tlv_59,
	&ett_tlv_60,
	&ett_tlv_61,
	&ett_tlv_62,
	&ett_tlv_63,
	&ett_tlv_64,
	&ett_tlv_65,
	&ett_tlv_66,
	&ett_tlv_67,
	&ett_tlv_68,
	&ett_tlv_69,
	&ett_tlv_70,
	&ett_tlv_71,
	&ett_tlv_72,
	&ett_tlv_73,
	&ett_tlv_74,
	&ett_tlv_75,
	&ett_tlv_76,
	&ett_tlv_77,
	&ett_tlv_78,
	&ett_tlv_79,
	&ett_tlv_80,
	&ett_tlv_81,
	&ett_tlv_82,
	&ett_tlv_83,
	&ett_tlv_84,
	&ett_tlv_85,
	&ett_tlv_86,
	&ett_tlv_87,
	&ett_tlv_88,
	&ett_tlv_89,
	&ett_tlv_90,
	&ett_tlv_91,
	&ett_tlv_92,
	&ett_tlv_93,
	&ett_tlv_94,
	&ett_tlv_95,
	&ett_tlv_96,
	&ett_tlv_97,
	&ett_tlv_98,
	&ett_tlv_99,
	&ett_tlv_100,
	&ett_tlv_101,
	&ett_tlv_102,
	&ett_tlv_103,
	&ett_tlv_104,
	&ett_tlv_105,
	&ett_tlv_106,
	&ett_tlv_107,
	&ett_tlv_108,
	&ett_tlv_109,
	&ett_tlv_110,
	&ett_tlv_111,
	&ett_tlv_112,
	&ett_tlv_113,
	&ett_tlv_114,
	&ett_tlv_115,
	&ett_tlv_116,
	&ett_tlv_117,
	&ett_tlv_118,
	&ett_tlv_119,
	&ett_tlv_120,
	&ett_tlv_121,
	&ett_tlv_122,
	&ett_tlv_123,
	&ett_tlv_124,
	&ett_tlv_125,
	&ett_tlv_126,
	&ett_tlv_127,
	&ett_tlv_128,
	&ett_tlv_129,
	&ett_tlv_130,
	&ett_tlv_131,
	&ett_tlv_132,
	&ett_tlv_133,
	&ett_tlv_134,
	&ett_tlv_135,
	&ett_tlv_136,
	&ett_tlv_137,
	&ett_tlv_138,
	&ett_tlv_139,
	&ett_tlv_140,
	&ett_tlv_141,
	&ett_tlv_142,
	&ett_tlv_143,
	&ett_tlv_144,
	&ett_tlv_145,
	&ett_tlv_146,
	&ett_tlv_147,
	&ett_tlv_148,
	&ett_tlv_149,
	&ett_tlv_150,
	&ett_tlv_151,
	&ett_tlv_152,
	&ett_tlv_153,
	&ett_tlv_154,
	&ett_tlv_155,
	&ett_tlv_156,
	&ett_tlv_157,
	&ett_tlv_158,
	&ett_tlv_159,
	&ett_tlv_160,
	&ett_tlv_161,
	&ett_tlv_162,
	&ett_tlv_163,
	&ett_tlv_164,
	&ett_tlv_165,
	&ett_tlv_166,
	&ett_tlv_167,
	&ett_tlv_168,
	&ett_tlv_169,
	&ett_tlv_170,
	&ett_tlv_171,
	&ett_tlv_172,
	&ett_tlv_173,
	&ett_tlv_174,
	&ett_tlv_175,
	&ett_tlv_176,
	&ett_tlv_177,
	&ett_tlv_178,
	&ett_tlv_179,
	&ett_tlv_180,
	&ett_tlv_181,
	&ett_tlv_182,
	&ett_tlv_183,
	&ett_tlv_184,
	&ett_tlv_185,
	&ett_tlv_186,
	&ett_tlv_187,
	&ett_tlv_188,
	&ett_tlv_189,
	&ett_tlv_190,
	&ett_tlv_191,
	&ett_tlv_192,
	&ett_tlv_193,
	&ett_tlv_194,
	&ett_tlv_195,
	&ett_tlv_196,
	&ett_tlv_197,
	&ett_tlv_198,
	&ett_tlv_199,
	&ett_tlv_200,
	&ett_tlv_201,
	&ett_tlv_202,
	&ett_tlv_203,
	&ett_tlv_204,
	&ett_tlv_205,
	&ett_tlv_206,
	&ett_tlv_207,
	&ett_tlv_208,
	&ett_tlv_209,
	&ett_tlv_210,
	&ett_tlv_211,
	&ett_tlv_212,
	&ett_tlv_213,
	&ett_tlv_214,
	&ett_tlv_215,
	&ett_tlv_216,
	&ett_tlv_217,
	&ett_tlv_218,
	&ett_tlv_219,
	&ett_tlv_220,
	&ett_tlv_221,
	&ett_tlv_222,
	&ett_tlv_223,
	&ett_tlv_224,
	&ett_tlv_225,
	&ett_tlv_226,
	&ett_tlv_227,
	&ett_tlv_228,
	&ett_tlv_229,
	&ett_tlv_230,
	&ett_tlv_231,
	&ett_tlv_232,
	&ett_tlv_233,
	&ett_tlv_234,
	&ett_tlv_235,
	&ett_tlv_236,
	&ett_tlv_237,
	&ett_tlv_238,
	&ett_tlv_239,
	&ett_tlv_240,
	&ett_tlv_241,
	&ett_tlv_242,
	&ett_tlv_243,
	&ett_tlv_244,
	&ett_tlv_245,
	&ett_tlv_246,
	&ett_tlv_247,
	&ett_tlv_248,
	&ett_tlv_249,
	&ett_tlv_250,
	&ett_tlv_251,
	&ett_tlv_252,
	&ett_tlv_253,
	&ett_tlv_254,
	&ett_tlv_255
};

#if 0 /* XXX: not used ?? */
/* Local Variables */
static gint ett_wimax = -1;
static gint ett_wimax_tlv = -1;
static gint ett_wimax_fch = -1;
static gint ett_wimax_cdma = -1;
static gint ett_wimax_ffb = -1;
#endif

static const gchar tlv_val_1byte[] = "TLV value: %s (0x%02x)";
static const gchar tlv_val_2byte[] = "TLV value: %s (0x%04x)";
static const gchar tlv_val_3byte[] = "TLV value: %s (0x%06x)";
static const gchar tlv_val_4byte[] = "TLV value: %s (0x%08x)";
static const gchar tlv_val_5byte[] = "TLV value: %s (0x%08x...)";

/*************************************************************/
/* add_tlv_subtree()                                         */
/* Return a pointer to a proto_item of a TLV value that      */
/* already contains the type and length of the given TLV.    */
/*   tree          - the parent to which the new tree will   */
/*                   be attached                             */
/*   hfindex       - the index of the item to be attached    */
/*   tvb           - a pointer to the packet data            */
/*   start         - offset within the packet                */
/*   length        - length of this item                     */
/*   encoding      - encoding for proto_tree_add_item        */
/* return:                                                   */
/*   pointer to a proto_item                                 */
/*************************************************************/
proto_item *add_tlv_subtree(tlv_info_t *self, proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, const guint encoding)
{
	header_field_info *hf;
	proto_tree *tlv_tree;
	proto_item *tlv_item;
	gint tlv_value_length, tlv_val_offset;
	guint8 size_of_tlv_length_field;
	guint8 tlv_type;

	/* Make sure we're dealing with a valid TLV here */
	if (get_tlv_type(self) < 0)
		return tree;

	/* Retrieve the necessary TLV information */
	tlv_val_offset = get_tlv_value_offset(self);
	tlv_value_length = get_tlv_length(self);
	size_of_tlv_length_field = get_tlv_size_of_length(self);
	tlv_type = get_tlv_type(self);

	hf = proto_registrar_get_nth(hfindex);

	tlv_item = proto_tree_add_text(tree, tvb, start, tlv_value_length+tlv_val_offset, "%s", hf->name);
	tlv_tree = proto_item_add_subtree(tlv_item, *ett_tlv[tlv_type]);

	proto_tree_add_uint(tlv_tree, hf_tlv_type, tvb, start, 1, tlv_type);
	if (size_of_tlv_length_field > 0) /* It is */
	{
		/* display the length of the length field TLV */
		proto_tree_add_uint(tlv_tree, hf_tlv_length_size, tvb, start+1, 1, size_of_tlv_length_field);
		/* display the TLV length */
		proto_tree_add_uint(tlv_tree, hf_tlv_length, tvb, start+2, size_of_tlv_length_field, tlv_value_length);
	} else { /* It is not */
		/* display the TLV length */
		proto_tree_add_uint(tlv_tree, hf_tlv_length, tvb, start+1, 1, tlv_value_length);
	}

	tlv_item = proto_tree_add_item(tlv_tree, hfindex, tvb, start+tlv_val_offset, tlv_value_length, encoding);

	/* Return a pointer to the value level */
	return tlv_item;
}

/*************************************************************/
/* add_tlv_subtree_no_item()                                 */
/* Return a pointer to a proto_tree of a TLV value that      */
/* already contains the type and length, but no value        */
/*   tree          - the parent to which the new tree will   */
/*                   be attached                             */
/*   hfindex       - the index of the item to be attached    */
/*   tvb           - a pointer to the packet data            */
/*   start         - offset within the packet                */
/*   length        - length of this item                     */
/* return:                                                   */
/*   pointer to a proto_tree (to then add value)             */
/*************************************************************/
proto_tree *add_tlv_subtree_no_item(tlv_info_t *self, proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start)
{
	header_field_info *hf;
	proto_tree *tlv_tree;
	proto_item *tlv_item;
	gint tlv_value_length, tlv_val_offset;
	guint8 size_of_tlv_length_field;
	guint8 tlv_type;

	/* Make sure we're dealing with a valid TLV here */
	if (get_tlv_type(self) < 0)
		return tree;

	/* Retrieve the necessary TLV information */
	tlv_val_offset = get_tlv_value_offset(self);
	tlv_value_length = get_tlv_length(self);
	size_of_tlv_length_field = get_tlv_size_of_length(self);
	tlv_type = get_tlv_type(self);

	hf = proto_registrar_get_nth(hfindex);

	tlv_item = proto_tree_add_text(tree, tvb, start, tlv_value_length+tlv_val_offset, "%s", hf->name);
	tlv_tree = proto_item_add_subtree(tlv_item, *ett_tlv[tlv_type]);

	proto_tree_add_uint(tlv_tree, hf_tlv_type, tvb, start, 1, tlv_type);
	if (size_of_tlv_length_field > 0) /* It is */
	{
		/* display the length of the length field TLV */
		proto_tree_add_uint(tlv_tree, hf_tlv_length_size, tvb, start+1, 1, size_of_tlv_length_field);
		/* display the TLV length */
		proto_tree_add_uint(tlv_tree, hf_tlv_length, tvb, start+2, size_of_tlv_length_field, tlv_value_length);
	} else { /* It is not */
		/* display the TLV length */
		proto_tree_add_uint(tlv_tree, hf_tlv_length, tvb, start+1, 1, tlv_value_length);
	}

	/* Return a pointer to the tree level (to manually add item) */
	return tlv_tree;
}

/*************************************************************/
/* add_protocol_subtree()                                    */
/* Return a pointer to a proto_tree that already contains    */
/* the type and length of a given TLV.                       */
/*   tree          - the parent to which the new tree will   */
/*                   be attached                             */
/*   hfindex       - the index of the item to be attached    */
/*   tvb           - a pointer to the packet data            */
/*   start         - offset within the packet                */
/*   length        - length of this item                     */
/*   format        - printf style formatting string          */
/*   ...	   - arguments to format                     */
/* return:                                                   */
/*   pointer to a proto_tree                                 */
/*************************************************************/
proto_tree *add_protocol_subtree(tlv_info_t *self, gint idx, proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length _U_, const char *label)
{
	/* Declare local variables */
	proto_tree *tlv_tree;
	proto_item *tlv_item;
	gint tlv_value_length, tlv_val_offset;
	guint8 size_of_tlv_length_field;
	guint8 tlv_type;
	guint32 tlv_value;
	const gchar *hex_fmt;

	/* Make sure we're dealing with a valid TLV here */
	if (get_tlv_type(self) < 0)
		return tree;

	/* Retrieve the necessary TLV information */
	tlv_val_offset = get_tlv_value_offset(self);
	tlv_value_length = get_tlv_length(self);
	size_of_tlv_length_field = get_tlv_size_of_length(self);
	tlv_type = get_tlv_type(self);

	/* display the TLV name and display the value in hex. Highlight type, length, and value. */
	tlv_item = proto_tree_add_protocol_format(tree, hfindex, tvb, start, tlv_value_length+tlv_val_offset, "%s (%u byte(s))", label, tlv_value_length);
	tlv_tree = proto_item_add_subtree(tlv_item, *ett_tlv[tlv_type]);

	proto_tree_add_uint(tlv_tree, hf_tlv_type, tvb, start, 1, tlv_type);
	if (size_of_tlv_length_field > 0) /* It is */
	{
		/* display the length of the length field TLV */
		proto_tree_add_uint(tlv_tree, hf_tlv_length_size, tvb, start+1, 1, size_of_tlv_length_field);
		/* display the TLV length */
		proto_tree_add_uint(tlv_tree, hf_tlv_length, tvb, start+2, size_of_tlv_length_field, tlv_value_length);
	} else { /* It is not */
		/* display the TLV length */
		proto_tree_add_uint(tlv_tree, hf_tlv_length, tvb, start+1, 1, tlv_value_length);
	}

	/* display the TLV value and make it a subtree */
	switch (tlv_value_length)
	{
		case 1:
			tlv_value = tvb_get_guint8(tvb, start+tlv_val_offset);
			hex_fmt = tlv_val_1byte;
			break;
		case 2:
			tlv_value = tvb_get_ntohs(tvb, start+tlv_val_offset);
			hex_fmt = tlv_val_2byte;
			break;
		case 3:
			tlv_value = tvb_get_ntoh24(tvb, start+tlv_val_offset);
			hex_fmt = tlv_val_3byte;
			break;
		case 4:
			tlv_value = tvb_get_ntohl(tvb, start+tlv_val_offset);
			hex_fmt = tlv_val_4byte;
			break;
		default:
			tlv_value = tvb_get_ntohl(tvb, start+tlv_val_offset);
			hex_fmt = tlv_val_5byte;
			break;
	}
	/* Show "TLV value: " */
	tlv_item = proto_tree_add_text(tlv_tree, tvb, start+tlv_val_offset, tlv_value_length, hex_fmt, label, tlv_value);
	tlv_tree = proto_item_add_subtree(tlv_item, idx);

	/* Return a pointer to the value level */
	return tlv_tree;
}



/* WiMax protocol dissector */
static void dissect_wimax(tvbuff_t *tvb _U_, packet_info *pinfo, proto_tree *tree _U_)
{
	/* display the WiMax protocol name */
	col_set_str(pinfo->cinfo, COL_PROTOCOL, "WiMax");
	/* Clear out stuff in the info column */
	col_clear(pinfo->cinfo, COL_INFO);
}

gboolean is_down_link(packet_info *pinfo)
{
	if (pinfo->p2p_dir == P2P_DIR_RECV)
		return TRUE;
	if (pinfo->p2p_dir == P2P_DIR_UNKNOWN)
		if(bs_address.len && !CMP_ADDRESS(&bs_address, &pinfo->src))
			return TRUE;
	return FALSE;
}


/* Register Wimax Protocol */
void proto_register_wimax(void)
{
	static hf_register_info hf[] = {
		{ &hf_tlv_type, { "TLV type", "wmx.tlv_type", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
		{ &hf_tlv_length, { "TLV length", "wmx.tlv_length", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
		{ &hf_tlv_length_size, { "Size of TLV length field", "wmx.tlv_length_size", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
	};

/* Setup protocol subtree array */
#if 0  /* XXX: not used ?? */
	static gint *ett[] =
		{
			&ett_wimax,
			&ett_wimax_tlv,
			&ett_wimax_fch,
			&ett_wimax_cdma,
			&ett_wimax_ffb,
		};
#endif

	module_t *wimax_module;

	/* Register the WiMax protocols here */
	proto_wimax = proto_register_protocol (
		"WiMax Protocol", /* name       */
		"WiMax (wmx)",    /* short name */
		"wmx"             /* abbrev     */
		);

	proto_register_field_array(proto_wimax, hf, array_length(hf));

#if 0  /* XXX: not used ?? */
	/* Register the WiMax protocol subtree array */
	proto_register_subtree_array(ett, array_length(ett));
#endif

	/* Register the WiMax dissector */
	register_dissector("wmx", dissect_wimax, proto_wimax);

#if 0 /* XXX: see comment at proto_reg_handoff_wimax() */
	wimax_module = prefs_register_protocol(proto_wimax, proto_reg_handoff_wimax);
#endif
	wimax_module = prefs_register_protocol(proto_wimax, NULL);

	prefs_register_uint_preference(wimax_module, "basic_cid_max",
				       "Maximum Basic CID",
				       "Set the maximum Basic CID"
				       " used in the Wimax decoder"
				       " (if other than the default of 320)."
				       "  Note: The maximum Primary CID is"
				       " double the maximum Basic CID.",
				       10, &global_cid_max_basic);

	prefs_register_bool_preference(wimax_module, "corrigendum_2_version",
				       "Corrigendum 2 Version",
				       "Set to TRUE to use the Corrigendum"
				       " 2 version of Wimax message decoding."
				       " Set to FALSE to use the 802.16e-2005"
				       "  version.",
				       &include_cor2_changes);
	prefs_register_obsolete_preference(wimax_module, "wimax.basic_cid_max");
	prefs_register_obsolete_preference(wimax_module, "wimax.corrigendum_2_version");

#if 0 /* XXX: see comment at proto_reg_handoff_wimax() */
	register_dissector_table("wimax.max_basic_cid", "Max Basic CID", FT_UINT16, BASE_DEC);
	register_dissector_table("wimax.corrigendum_2_version", "Corrigendum 2 Version", FT_UINT16, BASE_DEC);
#endif
	proto_register_subtree_array(ett_tlv, array_length(ett_tlv));
}

/* The registration hand-off routine for the max_basic_cid pref */
void
proto_reg_handoff_wimax(void)
{
#if 0 /* XXX: I don't see any reason for keeping the preference values
       *      in two dissector tables so I've commented out this code.
       */
	static int wimax_prefs_initialized = FALSE;
	static dissector_handle_t wimax_handle;

	if(!wimax_prefs_initialized)
	{
                wimax_handle = create_dissector_handle(dissect_wimax, proto_wimax);
                wimax_prefs_initialized = TRUE;
        } else {
                dissector_delete_uint("wimax.max_basic_cid", global_cid_max_basic, wimax_handle);
                dissector_delete_uint("wimax.corrigendum_2_version", include_cor2_changes, wimax_handle);

        }

	dissector_add_uint("wimax.max_basic_cid", global_cid_max_basic, wimax_handle);
	dissector_add_uint("wimax.corrigendum_2_version", include_cor2_changes, wimax_handle);
#endif
}
