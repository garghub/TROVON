int F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
int V_4 ;
struct V_5 V_6 ;
struct V_7 V_7 ;
T_3 * V_8 ;
V_9 = V_10 ;
V_4 = F_2 ( V_6 . V_11 , sizeof V_6 . V_11 , V_1 -> V_12 ) ;
if ( V_4 != sizeof V_6 . V_11 ) {
* V_2 = F_3 ( V_1 -> V_12 , V_3 ) ;
if ( * V_2 != 0 )
return - 1 ;
return 0 ;
}
if ( memcmp ( V_6 . V_11 , V_13 , sizeof V_13 ) != 0 )
return 0 ;
V_9 = V_10 ;
V_4 = F_2 ( ( char * ) & V_6 + sizeof V_6 . V_11 ,
sizeof V_6 - sizeof V_6 . V_11 , V_1 -> V_12 ) ;
if ( V_4 != sizeof V_6 - sizeof V_6 . V_11 ) {
* V_2 = F_3 ( V_1 -> V_12 , V_3 ) ;
if ( * V_2 != 0 )
return - 1 ;
return 0 ;
}
V_1 -> V_14 = V_15 ;
V_8 = ( T_3 * ) F_4 ( sizeof( T_3 ) ) ;
V_1 -> V_16 = ( void * ) V_8 ;
V_1 -> V_17 = V_18 ;
V_1 -> V_19 = V_20 ;
V_7 . V_21 = F_5 ( & V_6 . V_22 ) - 1900 ;
V_7 . V_23 = F_5 ( & V_6 . V_24 ) - 1 ;
V_7 . V_25 = F_5 ( & V_6 . V_26 ) ;
V_7 . V_27 = V_6 . V_28 ;
V_7 . V_29 = V_6 . V_30 ;
V_7 . V_31 = V_6 . V_32 ;
V_7 . V_33 = - 1 ;
V_8 -> V_34 = mktime ( & V_7 ) ;
V_1 -> V_35 = V_36 ;
V_1 -> V_37 = 0 ;
V_1 -> V_38 = V_39 ;
return 1 ;
}
static T_4 V_18 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_5 * V_40 )
{
T_3 * V_8 = ( T_3 * ) V_1 -> V_16 ;
struct V_41 V_6 ;
T_6 V_42 ;
T_6 V_43 ;
T_6 V_44 ;
for (; ; ) {
* V_40 = F_6 ( V_1 -> V_12 ) ;
if ( ! F_7 ( V_1 -> V_12 , & V_6 , & V_1 -> V_45 ,
V_2 , V_3 ) )
return FALSE ;
V_42 = F_5 ( V_6 . V_42 ) ;
if ( V_42 < ( sizeof V_6 - sizeof V_6 . V_42 ) ) {
* V_2 = V_46 ;
* V_3 = F_8 ( L_1 ,
V_42 , ( unsigned int ) ( sizeof V_6 - sizeof V_6 . V_42 ) ) ;
return FALSE ;
}
V_43 = V_42 - ( sizeof V_6 - sizeof V_6 . V_42 ) ;
if ( V_43 != 0 ) {
F_9 ( V_1 -> V_47 , V_43 ) ;
if ( ! F_10 ( V_1 -> V_12 , F_11 ( V_1 -> V_47 ) ,
V_43 , V_2 , V_3 ) )
return FALSE ;
}
#if 0
packet++;
#endif
switch ( V_6 . V_48 ) {
case V_49 :
#if 0
fprintf(stderr, "Packet %u: type 0x%02x (AETHRA_ISDN_LINK)\n",
packet, hdr.rec_type);
#endif
switch ( V_6 . V_50 & V_51 ) {
case V_52 :
#if 0
fprintf(stderr, " subtype 0x%02x (AETHRA_ISDN_LINK_LAPD)\n", hdr.flags & AETHRA_ISDN_LINK_SUBTYPE);
#endif
goto V_53;
case V_54 :
#if 0
fprintf(stderr, " subtype 0x%02x (AETHRA_ISDN_LINK_SA_BITS)\n", hdr.flags & AETHRA_ISDN_LINK_SUBTYPE);
#endif
break;
case V_55 :
#if 0
fprintf(stderr, " subtype 0x%02x (AETHRA_ISDN_LINK_ALL_ALARMS_CLEARED)\n", hdr.flags & AETHRA_ISDN_LINK_SUBTYPE);
#endif
break;
default:
#if 0
fprintf(stderr, " subtype 0x%02x, packet_size %u, direction 0x%02x\n",
hdr.flags & AETHRA_ISDN_LINK_SUBTYPE, packet_size, hdr.flags & AETHRA_U_TO_N);
#endif
break;
}
break;
default:
#if 0
fprintf(stderr, "Packet %u: type 0x%02x, packet_size %u, flags 0x%02x\n",
packet, hdr.rec_type, packet_size, hdr.flags);
#endif
break;
}
}
V_53:
V_44 = F_12 ( V_6 . V_56 ) ;
V_1 -> V_57 . V_58 = V_59 ;
V_1 -> V_57 . V_60 . V_61 = V_8 -> V_34 + ( V_44 / 1000 ) ;
V_1 -> V_57 . V_60 . V_62 = ( V_44 % 1000 ) * 1000000 ;
V_1 -> V_57 . V_63 = V_43 ;
V_1 -> V_57 . V_64 = V_43 ;
return TRUE ;
}
static T_4
V_20 ( T_1 * V_1 , T_5 V_65 ,
union V_66 * V_45 , T_7 * V_67 , int V_68 ,
int * V_2 , T_2 * * V_3 )
{
struct V_41 V_6 ;
if ( F_13 ( V_1 -> V_69 , V_65 , V_70 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_7 ( V_1 -> V_69 , & V_6 , V_45 , V_2 , V_3 ) )
return FALSE ;
if ( ! F_10 ( V_1 -> V_69 , V_67 , V_68 , V_2 , V_3 ) )
return FALSE ;
return TRUE ;
}
static T_4
F_7 ( T_8 V_12 , struct V_41 * V_6 ,
union V_66 * V_45 , int * V_2 , T_2 * * V_3 )
{
int V_4 ;
V_9 = V_10 ;
V_4 = F_2 ( V_6 , sizeof *V_6 , V_12 ) ;
if ( V_4 != sizeof *V_6 ) {
* V_2 = F_3 ( V_12 , V_3 ) ;
if ( * V_2 == 0 && V_4 != 0 )
* V_2 = V_71 ;
return FALSE ;
}
V_45 -> V_72 . V_73 = ( V_6 -> V_50 & V_74 ) ;
V_45 -> V_72 . V_75 = 0 ;
return TRUE ;
}
static T_4
F_10 ( T_8 V_12 , T_7 * V_67 , int V_68 , int * V_2 ,
T_2 * * V_3 )
{
int V_4 ;
V_9 = V_10 ;
V_4 = F_2 ( V_67 , V_68 , V_12 ) ;
if ( V_4 != V_68 ) {
* V_2 = F_3 ( V_12 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_71 ;
return FALSE ;
}
return TRUE ;
}
