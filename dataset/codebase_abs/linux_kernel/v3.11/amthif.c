void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = NULL ;
V_2 -> V_4 = 0 ;
V_2 -> V_5 = 0 ;
V_2 -> V_6 = false ;
V_2 -> V_7 = false ;
V_2 -> V_8 = V_9 ;
V_2 -> V_10 = 0 ;
}
int F_2 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = & V_2 -> V_13 ;
unsigned char * V_14 ;
int V_15 , V_16 ;
V_2 -> V_8 = V_9 ;
F_3 ( V_12 , V_2 ) ;
V_16 = F_4 ( V_2 , & V_17 ) ;
if ( V_16 < 0 ) {
F_5 ( & V_2 -> V_18 -> V_2 , L_1 ) ;
return - V_19 ;
}
V_12 -> V_20 = V_2 -> V_21 [ V_16 ] . V_22 ;
V_2 -> V_23 = V_2 -> V_21 [ V_16 ] . V_24 . V_25 ;
F_6 ( & V_2 -> V_18 -> V_2 , L_2 ,
V_2 -> V_21 [ V_16 ] . V_24 . V_25 ) ;
F_7 ( V_2 -> V_26 ) ;
V_2 -> V_26 = NULL ;
V_14 = F_8 ( V_2 -> V_23 ,
sizeof( unsigned char ) , V_27 ) ;
if ( ! V_14 ) {
F_9 ( & V_2 -> V_18 -> V_2 , L_3 ) ;
return - V_28 ;
}
V_2 -> V_26 = V_14 ;
V_15 = F_10 ( V_12 , V_29 ) ;
if ( V_15 < 0 ) {
F_9 ( & V_2 -> V_18 -> V_2 , L_4 ) ;
return - V_19 ;
}
V_12 -> V_30 = V_31 ;
if ( F_11 ( V_2 , V_12 ) ) {
F_6 ( & V_2 -> V_18 -> V_2 , L_5 ) ;
V_12 -> V_30 = V_32 ;
V_12 -> V_33 = 0 ;
} else {
V_12 -> V_34 = V_35 ;
}
return 0 ;
}
struct V_36 * F_12 ( struct V_1 * V_2 ,
struct V_37 * V_37 )
{
struct V_36 * V_38 = NULL ;
struct V_36 * V_39 = NULL ;
F_13 (pos, next,
&dev->amthif_rd_complete_list.list, list) {
if ( V_38 -> V_12 && V_38 -> V_12 == & V_2 -> V_13 &&
V_38 -> V_40 == V_37 )
return V_38 ;
}
return NULL ;
}
int F_14 ( struct V_1 * V_2 , struct V_37 * V_37 ,
char T_1 * V_41 , T_2 V_42 , T_3 * V_43 )
{
int V_44 ;
int V_45 ;
struct V_36 * V_46 = NULL ;
struct V_11 * V_12 = V_37 -> V_47 ;
unsigned long V_48 ;
int V_16 ;
if ( ! V_12 || V_12 != & V_2 -> V_13 ) {
F_6 ( & V_2 -> V_18 -> V_2 , L_6 ) ;
return - V_49 ;
}
V_16 = F_15 ( V_2 , V_2 -> V_13 . V_20 ) ;
if ( V_16 < 0 ) {
F_6 ( & V_2 -> V_18 -> V_2 , L_7 ) ;
return - V_50 ;
}
F_6 ( & V_2 -> V_18 -> V_2 , L_8 ) ;
V_46 = F_12 ( V_2 , V_37 ) ;
if ( V_46 == NULL && V_37 -> V_51 & V_52 )
return - V_53 ;
F_6 ( & V_2 -> V_18 -> V_2 , L_9 ) ;
while ( V_46 == NULL ) {
F_16 ( & V_2 -> V_54 ) ;
V_45 = F_17 ( V_2 -> V_13 . V_55 ,
( V_46 = F_12 ( V_2 , V_37 ) ) ) ;
F_18 ( & V_2 -> V_54 ) ;
if ( V_45 )
return - V_56 ;
F_6 ( & V_2 -> V_18 -> V_2 , L_10 ) ;
}
F_6 ( & V_2 -> V_18 -> V_2 , L_11 ) ;
V_2 -> V_10 = 0 ;
if ( V_46 ) {
V_48 = V_46 -> V_57 +
F_19 ( V_58 ) ;
F_6 ( & V_2 -> V_18 -> V_2 , L_12 ,
V_48 ) ;
if ( F_20 ( V_59 , V_48 ) ) {
F_6 ( & V_2 -> V_18 -> V_2 , L_13 ) ;
F_21 ( & V_46 -> V_60 ) ;
V_44 = - V_49 ;
goto free;
}
}
if ( V_46 -> V_61 >= * V_43 && V_42 >= ( V_46 -> V_61 - * V_43 ) )
F_21 ( & V_46 -> V_60 ) ;
else if ( V_46 -> V_61 > 0 && V_46 -> V_61 <= * V_43 ) {
F_21 ( & V_46 -> V_60 ) ;
V_44 = 0 ;
goto free;
}
F_6 ( & V_2 -> V_18 -> V_2 , L_14 ,
V_46 -> V_62 . V_63 ) ;
F_6 ( & V_2 -> V_18 -> V_2 , L_15 , V_46 -> V_61 ) ;
V_42 = F_22 ( T_2 , V_42 , ( V_46 -> V_61 - * V_43 ) ) ;
if ( F_23 ( V_41 , V_46 -> V_62 . V_64 + * V_43 , V_42 ) )
V_44 = - V_65 ;
else {
V_44 = V_42 ;
if ( ( * V_43 + V_42 ) < V_46 -> V_61 ) {
* V_43 += V_42 ;
goto V_66;
}
}
free:
F_6 ( & V_2 -> V_18 -> V_2 , L_16 ) ;
* V_43 = 0 ;
F_24 ( V_46 ) ;
V_66:
return V_44 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_36 * V_46 )
{
struct V_67 V_68 ;
int V_15 ;
if ( ! V_2 || ! V_46 )
return - V_50 ;
F_6 ( & V_2 -> V_18 -> V_2 , L_17 ) ;
V_2 -> V_8 = V_69 ;
V_2 -> V_3 = V_46 ;
V_2 -> V_70 = V_46 -> V_40 ;
V_2 -> V_6 = false ;
V_2 -> V_7 = true ;
V_2 -> V_4 = V_46 -> V_71 . V_63 ;
memcpy ( V_2 -> V_26 , V_46 -> V_71 . V_64 ,
V_46 -> V_71 . V_63 ) ;
V_15 = F_26 ( & V_2 -> V_13 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( V_15 && V_2 -> V_72 ) {
V_15 = 0 ;
V_2 -> V_72 = false ;
if ( V_46 -> V_71 . V_63 > F_27 ( V_2 ) ) {
V_68 . V_42 = F_27 ( V_2 ) ;
V_68 . V_73 = 0 ;
} else {
V_68 . V_42 = V_46 -> V_71 . V_63 ;
V_68 . V_73 = 1 ;
}
V_68 . V_74 = V_2 -> V_13 . V_33 ;
V_68 . V_75 = V_2 -> V_13 . V_20 ;
V_68 . V_76 = 0 ;
V_2 -> V_5 += V_68 . V_42 ;
if ( F_28 ( V_2 , & V_68 ,
( unsigned char * ) V_2 -> V_26 ) )
return - V_50 ;
if ( V_68 . V_73 ) {
if ( F_29 ( & V_2 -> V_13 ) )
return - V_50 ;
V_2 -> V_77 = true ;
V_2 -> V_8 = V_78 ;
F_6 ( & V_2 -> V_18 -> V_2 , L_18 ) ;
V_2 -> V_3 = V_46 ;
V_2 -> V_70 = V_46 -> V_40 ;
F_30 ( & V_46 -> V_60 , & V_2 -> V_79 . V_60 ) ;
} else {
F_6 ( & V_2 -> V_18 -> V_2 , L_19 ) ;
F_30 ( & V_46 -> V_60 , & V_2 -> V_80 . V_60 ) ;
}
} else {
if ( ! V_2 -> V_72 )
F_6 ( & V_2 -> V_18 -> V_2 , L_20 ) ;
F_6 ( & V_2 -> V_18 -> V_2 , L_21 ) ;
F_30 ( & V_46 -> V_60 , & V_2 -> V_80 . V_60 ) ;
}
return 0 ;
}
int F_31 ( struct V_1 * V_2 , struct V_36 * V_46 )
{
int V_15 ;
if ( ! V_2 || ! V_46 )
return - V_50 ;
V_15 = F_32 ( V_46 , V_2 -> V_23 ) ;
if ( V_15 )
return V_15 ;
V_46 -> V_81 = V_82 ;
if ( ! F_33 ( & V_2 -> V_83 . V_60 ) ||
V_2 -> V_8 != V_9 ) {
F_6 ( & V_2 -> V_18 -> V_2 ,
L_22 , V_2 -> V_8 ) ;
F_6 ( & V_2 -> V_18 -> V_2 , L_23 ) ;
F_30 ( & V_46 -> V_60 , & V_2 -> V_83 . V_60 ) ;
return 0 ;
}
return F_25 ( V_2 , V_46 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
struct V_36 * V_38 = NULL ;
struct V_36 * V_39 = NULL ;
int V_84 ;
if ( ! V_2 )
return;
V_2 -> V_4 = 0 ;
V_2 -> V_5 = 0 ;
V_2 -> V_6 = false ;
V_2 -> V_7 = true ;
V_2 -> V_8 = V_9 ;
V_2 -> V_10 = 0 ;
V_2 -> V_70 = NULL ;
F_6 ( & V_2 -> V_18 -> V_2 , L_24 ) ;
F_13 (pos, next, &dev->amthif_cmd_list.list, list) {
F_21 ( & V_38 -> V_60 ) ;
if ( V_38 -> V_12 && V_38 -> V_12 == & V_2 -> V_13 ) {
V_84 = F_25 ( V_2 , V_38 ) ;
if ( V_84 ) {
F_6 ( & V_2 -> V_18 -> V_2 ,
L_25 ,
V_84 ) ;
return;
}
break;
}
}
}
unsigned int F_35 ( struct V_1 * V_2 ,
struct V_37 * V_37 , T_4 * V_55 )
{
unsigned int V_85 = 0 ;
F_16 ( & V_2 -> V_54 ) ;
F_36 ( V_37 , & V_2 -> V_13 . V_55 , V_55 ) ;
F_18 ( & V_2 -> V_54 ) ;
if ( V_2 -> V_8 == V_86 &&
V_2 -> V_70 == V_37 ) {
V_85 |= ( V_87 | V_88 ) ;
F_6 ( & V_2 -> V_18 -> V_2 , L_26 ) ;
F_34 ( V_2 ) ;
}
return V_85 ;
}
int F_37 ( struct V_11 * V_12 , struct V_36 * V_46 ,
T_5 * V_89 , struct V_36 * V_90 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_67 V_68 ;
T_2 V_91 = V_2 -> V_4 - V_2 -> V_5 ;
T_6 V_92 = F_38 ( V_91 ) ;
V_68 . V_74 = V_12 -> V_33 ;
V_68 . V_75 = V_12 -> V_20 ;
V_68 . V_76 = 0 ;
if ( * V_89 >= V_92 ) {
V_68 . V_42 = V_91 ;
V_68 . V_73 = 1 ;
} else if ( * V_89 == V_2 -> V_93 ) {
V_92 = * V_89 ;
V_91 = ( * V_89 * sizeof( T_6 ) ) - sizeof( struct V_67 ) ;
V_68 . V_42 = V_91 ;
V_68 . V_73 = 0 ;
} else {
return 0 ;
}
F_6 ( & V_2 -> V_18 -> V_2 , V_94 , F_39 ( & V_68 ) ) ;
* V_89 -= V_92 ;
if ( F_28 ( V_2 , & V_68 ,
V_2 -> V_26 + V_2 -> V_5 ) ) {
V_2 -> V_8 = V_9 ;
V_12 -> V_84 = - V_50 ;
F_21 ( & V_46 -> V_60 ) ;
return - V_50 ;
}
if ( F_29 ( V_12 ) )
return - V_50 ;
V_2 -> V_5 += V_68 . V_42 ;
V_12 -> V_84 = 0 ;
if ( V_68 . V_73 ) {
V_2 -> V_8 = V_78 ;
V_2 -> V_77 = true ;
V_46 -> V_61 = V_2 -> V_5 ;
V_2 -> V_3 = V_46 ;
F_40 ( & V_46 -> V_60 , & V_2 -> V_79 . V_60 ) ;
}
return 0 ;
}
int F_41 ( struct V_1 * V_2 ,
struct V_67 * V_68 ,
struct V_36 * V_95 )
{
struct V_36 * V_46 ;
unsigned char * V_96 ;
F_42 ( V_68 -> V_75 != V_2 -> V_13 . V_20 ) ;
F_42 ( V_2 -> V_8 != V_97 ) ;
V_96 = V_2 -> V_26 + V_2 -> V_5 ;
F_42 ( V_2 -> V_23 < V_2 -> V_5 + V_68 -> V_42 ) ;
F_43 ( V_2 , V_96 , V_68 -> V_42 ) ;
V_2 -> V_5 += V_68 -> V_42 ;
if ( ! V_68 -> V_73 )
return 0 ;
F_6 ( & V_2 -> V_18 -> V_2 , L_27 ,
V_68 -> V_42 ) ;
F_6 ( & V_2 -> V_18 -> V_2 , L_28 ) ;
if ( ! V_2 -> V_3 )
return - V_50 ;
V_46 = V_2 -> V_3 ;
V_2 -> V_3 = NULL ;
if ( ! V_46 -> V_12 )
return - V_50 ;
V_2 -> V_98 = 0 ;
V_46 -> V_61 = V_2 -> V_5 ;
V_46 -> V_57 = V_59 ;
if ( V_2 -> V_7 && V_46 -> V_12 == & V_2 -> V_13 ) {
F_6 ( & V_2 -> V_18 -> V_2 , L_29 ) ;
F_6 ( & V_2 -> V_18 -> V_2 , L_30 ) ;
F_30 ( & V_46 -> V_60 , & V_95 -> V_60 ) ;
}
return 0 ;
}
int F_44 ( struct V_1 * V_2 , T_5 * V_89 )
{
T_6 V_92 = F_38 ( sizeof( struct V_99 ) ) ;
if ( * V_89 < V_92 )
return - V_100 ;
* V_89 -= V_92 ;
if ( F_45 ( V_2 , & V_2 -> V_13 ) ) {
F_6 ( & V_2 -> V_18 -> V_2 , L_31 ) ;
return - V_101 ;
}
F_6 ( & V_2 -> V_18 -> V_2 , L_32 ) ;
V_2 -> V_8 = V_97 ;
V_2 -> V_77 = false ;
V_2 -> V_5 = 0 ;
V_2 -> V_4 = 0 ;
V_2 -> V_98 = V_102 ;
V_2 -> V_72 = F_46 ( V_2 ) ;
return 0 ;
}
void F_47 ( struct V_1 * V_2 , struct V_36 * V_46 )
{
if ( V_2 -> V_6 != 1 ) {
V_2 -> V_8 = V_86 ;
V_2 -> V_98 = 0 ;
memcpy ( V_46 -> V_62 . V_64 ,
V_2 -> V_26 ,
V_2 -> V_5 ) ;
F_30 ( & V_46 -> V_60 , & V_2 -> V_103 . V_60 ) ;
F_6 ( & V_2 -> V_18 -> V_2 , L_33 ) ;
V_2 -> V_10 = V_59 ;
F_6 ( & V_2 -> V_18 -> V_2 , L_34 ,
V_2 -> V_10 ) ;
} else {
F_34 ( V_2 ) ;
}
F_6 ( & V_2 -> V_18 -> V_2 , L_35 ) ;
F_48 ( & V_2 -> V_13 . V_55 ) ;
}
static bool F_49 ( struct V_1 * V_2 ,
const struct V_37 * V_37 , struct V_104 * V_105 )
{
struct V_36 * V_106 = NULL ;
struct V_36 * V_107 = NULL ;
bool V_108 = false ;
F_13 (cb_pos, cb_next, mei_cb_list, list) {
if ( V_37 == V_106 -> V_40 ) {
F_21 ( & V_106 -> V_60 ) ;
if ( V_2 -> V_3 == V_106 ) {
V_2 -> V_3 = NULL ;
F_45 ( V_2 ,
& V_2 -> V_13 ) ;
}
F_24 ( V_106 ) ;
V_106 = NULL ;
V_108 = true ;
}
}
return V_108 ;
}
static bool F_50 ( struct V_1 * V_2 , struct V_37 * V_37 )
{
bool V_108 = false ;
F_49 ( V_2 , V_37 , & V_2 -> V_83 . V_60 ) ;
if ( F_49 ( V_2 , V_37 , & V_2 -> V_103 . V_60 ) )
V_108 = true ;
F_49 ( V_2 , V_37 , & V_2 -> V_109 . V_60 ) ;
if ( F_49 ( V_2 , V_37 , & V_2 -> V_110 . V_60 ) )
V_108 = true ;
if ( F_49 ( V_2 , V_37 , & V_2 -> V_79 . V_60 ) )
V_108 = true ;
if ( F_49 ( V_2 , V_37 , & V_2 -> V_80 . V_60 ) )
V_108 = true ;
if ( V_2 -> V_3 && ! V_108 ) {
if ( V_2 -> V_3 -> V_40 == V_37 ) {
F_24 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
V_108 = true ;
}
}
return V_108 ;
}
int F_51 ( struct V_1 * V_2 , struct V_37 * V_37 )
{
if ( V_2 -> V_111 > 0 )
V_2 -> V_111 -- ;
if ( V_2 -> V_70 == V_37 &&
V_2 -> V_8 != V_9 ) {
F_6 ( & V_2 -> V_18 -> V_2 , L_36 ,
V_2 -> V_8 ) ;
V_2 -> V_6 = true ;
if ( V_2 -> V_8 == V_86 ) {
F_6 ( & V_2 -> V_18 -> V_2 , L_37 ) ;
F_34 ( V_2 ) ;
}
}
if ( F_50 ( V_2 , V_37 ) )
V_2 -> V_8 = V_9 ;
return 0 ;
}
