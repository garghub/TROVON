void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = NULL ;
V_2 -> V_4 = 0 ;
V_2 -> V_5 = 0 ;
V_2 -> V_6 = false ;
V_2 -> V_7 = false ;
V_2 -> V_8 = V_9 ;
V_2 -> V_10 = 0 ;
V_2 -> V_11 = 0 ;
V_2 -> V_12 = 0 ;
}
int F_2 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_15 ;
unsigned char * V_16 ;
int V_17 , V_18 ;
V_2 -> V_8 = V_9 ;
F_3 ( V_14 , V_2 ) ;
V_18 = F_4 ( V_2 , & V_19 ) ;
if ( V_18 < 0 ) {
V_17 = V_18 ;
F_5 ( & V_2 -> V_20 -> V_2 ,
L_1 , V_17 ) ;
return V_17 ;
}
V_14 -> V_21 = V_2 -> V_22 [ V_18 ] . V_23 ;
V_2 -> V_24 = V_2 -> V_22 [ V_18 ] . V_25 . V_26 ;
F_6 ( & V_2 -> V_20 -> V_2 , L_2 ,
V_2 -> V_22 [ V_18 ] . V_25 . V_26 ) ;
F_7 ( V_2 -> V_27 ) ;
V_2 -> V_27 = NULL ;
V_16 = F_8 ( V_2 -> V_24 ,
sizeof( unsigned char ) , V_28 ) ;
if ( ! V_16 ) {
F_9 ( & V_2 -> V_20 -> V_2 , L_3 ) ;
return - V_29 ;
}
V_2 -> V_27 = V_16 ;
V_17 = F_10 ( V_14 , V_30 ) ;
if ( V_17 < 0 ) {
F_9 ( & V_2 -> V_20 -> V_2 ,
L_4 , V_17 ) ;
return V_17 ;
}
V_14 -> V_31 = V_32 ;
if ( F_11 ( V_2 , V_14 ) ) {
F_6 ( & V_2 -> V_20 -> V_2 , L_5 ) ;
V_14 -> V_31 = V_33 ;
V_14 -> V_34 = 0 ;
} else {
V_14 -> V_35 = V_36 ;
}
return 0 ;
}
struct V_37 * F_12 ( struct V_1 * V_2 ,
struct V_38 * V_38 )
{
struct V_37 * V_39 = NULL ;
struct V_37 * V_40 = NULL ;
F_13 (pos, next,
&dev->amthif_rd_complete_list.list, list) {
if ( V_39 -> V_14 && V_39 -> V_14 == & V_2 -> V_15 &&
V_39 -> V_41 == V_38 )
return V_39 ;
}
return NULL ;
}
int F_14 ( struct V_1 * V_2 , struct V_38 * V_38 ,
char T_1 * V_42 , T_2 V_43 , T_3 * V_44 )
{
int V_45 ;
int V_46 ;
struct V_37 * V_47 = NULL ;
struct V_13 * V_14 = V_38 -> V_48 ;
unsigned long V_49 ;
int V_18 ;
if ( ! V_14 || V_14 != & V_2 -> V_15 ) {
F_6 ( & V_2 -> V_20 -> V_2 , L_6 ) ;
return - V_50 ;
}
V_18 = F_15 ( V_2 , V_2 -> V_15 . V_21 ) ;
if ( V_18 < 0 ) {
F_6 ( & V_2 -> V_20 -> V_2 , L_7 ) ;
return - V_51 ;
}
F_6 ( & V_2 -> V_20 -> V_2 , L_8 ) ;
V_47 = F_12 ( V_2 , V_38 ) ;
if ( V_47 == NULL && V_38 -> V_52 & V_53 )
return - V_54 ;
F_6 ( & V_2 -> V_20 -> V_2 , L_9 ) ;
while ( V_47 == NULL ) {
F_16 ( & V_2 -> V_55 ) ;
V_46 = F_17 ( V_2 -> V_15 . V_56 ,
( V_47 = F_12 ( V_2 , V_38 ) ) ) ;
F_18 ( & V_2 -> V_55 ) ;
if ( V_46 )
return - V_57 ;
F_6 ( & V_2 -> V_20 -> V_2 , L_10 ) ;
}
F_6 ( & V_2 -> V_20 -> V_2 , L_11 ) ;
V_2 -> V_10 = 0 ;
if ( V_47 ) {
V_49 = V_47 -> V_58 +
F_19 ( V_59 ) ;
F_6 ( & V_2 -> V_20 -> V_2 , L_12 ,
V_49 ) ;
if ( F_20 ( V_60 , V_49 ) ) {
F_6 ( & V_2 -> V_20 -> V_2 , L_13 ) ;
F_21 ( & V_47 -> V_61 ) ;
V_45 = - V_50 ;
goto free;
}
}
if ( V_47 -> V_62 >= * V_44 && V_43 >= ( V_47 -> V_62 - * V_44 ) )
F_21 ( & V_47 -> V_61 ) ;
else if ( V_47 -> V_62 > 0 && V_47 -> V_62 <= * V_44 ) {
F_21 ( & V_47 -> V_61 ) ;
V_45 = 0 ;
goto free;
}
F_6 ( & V_2 -> V_20 -> V_2 , L_14 ,
V_47 -> V_63 . V_64 ) ;
F_6 ( & V_2 -> V_20 -> V_2 , L_15 , V_47 -> V_62 ) ;
V_43 = F_22 ( T_2 , V_43 , ( V_47 -> V_62 - * V_44 ) ) ;
if ( F_23 ( V_42 , V_47 -> V_63 . V_65 + * V_44 , V_43 ) )
V_45 = - V_66 ;
else {
V_45 = V_43 ;
if ( ( * V_44 + V_43 ) < V_47 -> V_62 ) {
* V_44 += V_43 ;
goto V_67;
}
}
free:
F_6 ( & V_2 -> V_20 -> V_2 , L_16 ) ;
* V_44 = 0 ;
F_24 ( V_47 ) ;
V_67:
return V_45 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_37 * V_47 )
{
struct V_68 V_69 ;
int V_17 ;
if ( ! V_2 || ! V_47 )
return - V_51 ;
F_6 ( & V_2 -> V_20 -> V_2 , L_17 ) ;
V_2 -> V_8 = V_70 ;
V_2 -> V_3 = V_47 ;
V_2 -> V_71 = V_47 -> V_41 ;
V_2 -> V_6 = false ;
V_2 -> V_7 = true ;
V_2 -> V_4 = V_47 -> V_72 . V_64 ;
memcpy ( V_2 -> V_27 , V_47 -> V_72 . V_65 ,
V_47 -> V_72 . V_64 ) ;
V_17 = F_26 ( & V_2 -> V_15 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_17 && V_2 -> V_73 ) {
V_17 = 0 ;
V_2 -> V_73 = false ;
if ( V_47 -> V_72 . V_64 > F_27 ( V_2 ) ) {
V_69 . V_43 = F_27 ( V_2 ) ;
V_69 . V_74 = 0 ;
} else {
V_69 . V_43 = V_47 -> V_72 . V_64 ;
V_69 . V_74 = 1 ;
}
V_69 . V_75 = V_2 -> V_15 . V_34 ;
V_69 . V_76 = V_2 -> V_15 . V_21 ;
V_69 . V_77 = 0 ;
V_69 . V_78 = 0 ;
V_2 -> V_5 += V_69 . V_43 ;
V_17 = F_28 ( V_2 , & V_69 , V_2 -> V_27 ) ;
if ( V_17 )
return V_17 ;
if ( V_69 . V_74 ) {
if ( F_29 ( & V_2 -> V_15 ) )
return - V_79 ;
V_2 -> V_80 = true ;
V_2 -> V_8 = V_81 ;
F_6 ( & V_2 -> V_20 -> V_2 , L_18 ) ;
V_2 -> V_3 = V_47 ;
V_2 -> V_71 = V_47 -> V_41 ;
F_30 ( & V_47 -> V_61 , & V_2 -> V_82 . V_61 ) ;
} else {
F_6 ( & V_2 -> V_20 -> V_2 , L_19 ) ;
F_30 ( & V_47 -> V_61 , & V_2 -> V_83 . V_61 ) ;
}
} else {
if ( ! V_2 -> V_73 )
F_6 ( & V_2 -> V_20 -> V_2 , L_20 ) ;
F_6 ( & V_2 -> V_20 -> V_2 , L_21 ) ;
F_30 ( & V_47 -> V_61 , & V_2 -> V_83 . V_61 ) ;
}
return 0 ;
}
int F_31 ( struct V_1 * V_2 , struct V_37 * V_47 )
{
int V_17 ;
if ( ! V_2 || ! V_47 )
return - V_51 ;
V_17 = F_32 ( V_47 , V_2 -> V_24 ) ;
if ( V_17 )
return V_17 ;
V_47 -> V_84 = V_85 ;
if ( ! F_33 ( & V_2 -> V_86 . V_61 ) ||
V_2 -> V_8 != V_9 ) {
F_6 ( & V_2 -> V_20 -> V_2 ,
L_22 , V_2 -> V_8 ) ;
F_6 ( & V_2 -> V_20 -> V_2 , L_23 ) ;
F_30 ( & V_47 -> V_61 , & V_2 -> V_86 . V_61 ) ;
return 0 ;
}
return F_25 ( V_2 , V_47 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
struct V_37 * V_39 = NULL ;
struct V_37 * V_40 = NULL ;
int V_87 ;
if ( ! V_2 )
return;
V_2 -> V_4 = 0 ;
V_2 -> V_5 = 0 ;
V_2 -> V_6 = false ;
V_2 -> V_7 = true ;
V_2 -> V_8 = V_9 ;
V_2 -> V_10 = 0 ;
V_2 -> V_71 = NULL ;
F_6 ( & V_2 -> V_20 -> V_2 , L_24 ) ;
F_13 (pos, next, &dev->amthif_cmd_list.list, list) {
F_21 ( & V_39 -> V_61 ) ;
if ( V_39 -> V_14 && V_39 -> V_14 == & V_2 -> V_15 ) {
V_87 = F_25 ( V_2 , V_39 ) ;
if ( V_87 ) {
F_6 ( & V_2 -> V_20 -> V_2 ,
L_25 ,
V_87 ) ;
return;
}
break;
}
}
}
unsigned int F_35 ( struct V_1 * V_2 ,
struct V_38 * V_38 , T_4 * V_56 )
{
unsigned int V_88 = 0 ;
F_36 ( V_38 , & V_2 -> V_15 . V_56 , V_56 ) ;
F_18 ( & V_2 -> V_55 ) ;
if ( ! F_37 ( & V_2 -> V_15 ) ) {
V_88 = V_89 ;
} else if ( V_2 -> V_8 == V_90 &&
V_2 -> V_71 == V_38 ) {
V_88 |= ( V_91 | V_92 ) ;
F_6 ( & V_2 -> V_20 -> V_2 , L_26 ) ;
F_34 ( V_2 ) ;
}
F_16 ( & V_2 -> V_55 ) ;
return V_88 ;
}
int F_38 ( struct V_13 * V_14 , struct V_37 * V_47 ,
T_5 * V_93 , struct V_37 * V_94 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_68 V_69 ;
T_2 V_95 = V_2 -> V_4 - V_2 -> V_5 ;
T_6 V_96 = F_39 ( V_95 ) ;
int V_45 ;
V_45 = F_26 ( V_14 ) ;
if ( V_45 < 0 )
return V_45 ;
if ( V_45 == 0 ) {
F_40 ( V_2 , V_14 , L_27 ) ;
return 0 ;
}
V_69 . V_75 = V_14 -> V_34 ;
V_69 . V_76 = V_14 -> V_21 ;
V_69 . V_77 = 0 ;
V_69 . V_78 = 0 ;
if ( * V_93 >= V_96 ) {
V_69 . V_43 = V_95 ;
V_69 . V_74 = 1 ;
} else if ( * V_93 == V_2 -> V_97 ) {
V_96 = * V_93 ;
V_95 = ( * V_93 * sizeof( T_6 ) ) - sizeof( struct V_68 ) ;
V_69 . V_43 = V_95 ;
V_69 . V_74 = 0 ;
} else {
return 0 ;
}
F_6 ( & V_2 -> V_20 -> V_2 , V_98 , F_41 ( & V_69 ) ) ;
* V_93 -= V_96 ;
V_45 = F_28 ( V_2 , & V_69 ,
V_2 -> V_27 + V_2 -> V_5 ) ;
if ( V_45 ) {
V_2 -> V_8 = V_9 ;
V_14 -> V_87 = V_45 ;
F_21 ( & V_47 -> V_61 ) ;
return V_45 ;
}
if ( F_29 ( V_14 ) )
return - V_79 ;
V_2 -> V_5 += V_69 . V_43 ;
V_14 -> V_87 = 0 ;
if ( V_69 . V_74 ) {
V_2 -> V_8 = V_81 ;
V_2 -> V_80 = true ;
V_47 -> V_62 = V_2 -> V_5 ;
V_2 -> V_3 = V_47 ;
F_42 ( & V_47 -> V_61 , & V_2 -> V_82 . V_61 ) ;
}
return 0 ;
}
int F_43 ( struct V_1 * V_2 ,
struct V_68 * V_69 ,
struct V_37 * V_99 )
{
struct V_37 * V_47 ;
unsigned char * V_100 ;
F_44 ( V_69 -> V_76 != V_2 -> V_15 . V_21 ) ;
F_44 ( V_2 -> V_8 != V_101 ) ;
V_100 = V_2 -> V_27 + V_2 -> V_5 ;
F_44 ( V_2 -> V_24 < V_2 -> V_5 + V_69 -> V_43 ) ;
F_45 ( V_2 , V_100 , V_69 -> V_43 ) ;
V_2 -> V_5 += V_69 -> V_43 ;
if ( ! V_69 -> V_74 )
return 0 ;
F_6 ( & V_2 -> V_20 -> V_2 , L_28 ,
V_69 -> V_43 ) ;
F_6 ( & V_2 -> V_20 -> V_2 , L_29 ) ;
if ( ! V_2 -> V_3 )
return - V_51 ;
V_47 = V_2 -> V_3 ;
V_2 -> V_3 = NULL ;
if ( ! V_47 -> V_14 )
return - V_51 ;
V_2 -> V_11 = 0 ;
V_47 -> V_62 = V_2 -> V_5 ;
V_47 -> V_58 = V_60 ;
if ( V_2 -> V_7 && V_47 -> V_14 == & V_2 -> V_15 ) {
F_6 ( & V_2 -> V_20 -> V_2 , L_30 ) ;
F_6 ( & V_2 -> V_20 -> V_2 , L_31 ) ;
F_30 ( & V_47 -> V_61 , & V_99 -> V_61 ) ;
}
return 0 ;
}
int F_46 ( struct V_1 * V_2 , T_5 * V_93 )
{
T_6 V_96 = F_39 ( sizeof( struct V_102 ) ) ;
if ( * V_93 < V_96 )
return - V_103 ;
* V_93 -= V_96 ;
if ( F_47 ( V_2 , & V_2 -> V_15 ) ) {
F_6 ( & V_2 -> V_20 -> V_2 , L_32 ) ;
return - V_79 ;
}
F_6 ( & V_2 -> V_20 -> V_2 , L_33 ) ;
V_2 -> V_8 = V_101 ;
V_2 -> V_80 = false ;
V_2 -> V_5 = 0 ;
V_2 -> V_4 = 0 ;
V_2 -> V_11 = V_104 ;
V_2 -> V_73 = F_48 ( V_2 ) ;
return 0 ;
}
void F_49 ( struct V_1 * V_2 , struct V_37 * V_47 )
{
if ( V_2 -> V_6 != 1 ) {
V_2 -> V_8 = V_90 ;
V_2 -> V_11 = 0 ;
memcpy ( V_47 -> V_63 . V_65 ,
V_2 -> V_27 ,
V_2 -> V_5 ) ;
F_30 ( & V_47 -> V_61 , & V_2 -> V_105 . V_61 ) ;
F_6 ( & V_2 -> V_20 -> V_2 , L_34 ) ;
V_2 -> V_10 = V_60 ;
F_6 ( & V_2 -> V_20 -> V_2 , L_35 ,
V_2 -> V_10 ) ;
} else {
F_34 ( V_2 ) ;
}
F_6 ( & V_2 -> V_20 -> V_2 , L_36 ) ;
F_50 ( & V_2 -> V_15 . V_56 ) ;
}
static bool F_51 ( struct V_1 * V_2 ,
const struct V_38 * V_38 , struct V_106 * V_107 )
{
struct V_37 * V_108 = NULL ;
struct V_37 * V_109 = NULL ;
bool V_110 = false ;
F_13 (cb_pos, cb_next, mei_cb_list, list) {
if ( V_38 == V_108 -> V_41 ) {
F_21 ( & V_108 -> V_61 ) ;
if ( V_2 -> V_3 == V_108 ) {
V_2 -> V_3 = NULL ;
F_47 ( V_2 ,
& V_2 -> V_15 ) ;
}
F_24 ( V_108 ) ;
V_108 = NULL ;
V_110 = true ;
}
}
return V_110 ;
}
static bool F_52 ( struct V_1 * V_2 , struct V_38 * V_38 )
{
bool V_110 = false ;
F_51 ( V_2 , V_38 , & V_2 -> V_86 . V_61 ) ;
if ( F_51 ( V_2 , V_38 , & V_2 -> V_105 . V_61 ) )
V_110 = true ;
F_51 ( V_2 , V_38 , & V_2 -> V_111 . V_61 ) ;
if ( F_51 ( V_2 , V_38 , & V_2 -> V_112 . V_61 ) )
V_110 = true ;
if ( F_51 ( V_2 , V_38 , & V_2 -> V_82 . V_61 ) )
V_110 = true ;
if ( F_51 ( V_2 , V_38 , & V_2 -> V_83 . V_61 ) )
V_110 = true ;
if ( V_2 -> V_3 && ! V_110 ) {
if ( V_2 -> V_3 -> V_41 == V_38 ) {
F_24 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
V_110 = true ;
}
}
return V_110 ;
}
int F_53 ( struct V_1 * V_2 , struct V_38 * V_38 )
{
if ( V_2 -> V_12 > 0 )
V_2 -> V_12 -- ;
if ( V_2 -> V_71 == V_38 &&
V_2 -> V_8 != V_9 ) {
F_6 ( & V_2 -> V_20 -> V_2 , L_37 ,
V_2 -> V_8 ) ;
V_2 -> V_6 = true ;
if ( V_2 -> V_8 == V_90 ) {
F_6 ( & V_2 -> V_20 -> V_2 , L_38 ) ;
F_34 ( V_2 ) ;
}
}
if ( F_52 ( V_2 , V_38 ) )
V_2 -> V_8 = V_9 ;
return 0 ;
}
