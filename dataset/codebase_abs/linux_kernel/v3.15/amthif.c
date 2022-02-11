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
F_5 ( & V_2 -> V_20 -> V_2 ,
L_1 , V_18 ) ;
return - V_21 ;
}
V_14 -> V_22 = V_2 -> V_23 [ V_18 ] . V_24 ;
V_2 -> V_25 = V_2 -> V_23 [ V_18 ] . V_26 . V_27 ;
F_6 ( & V_2 -> V_20 -> V_2 , L_2 ,
V_2 -> V_23 [ V_18 ] . V_26 . V_27 ) ;
F_7 ( V_2 -> V_28 ) ;
V_2 -> V_28 = NULL ;
V_16 = F_8 ( V_2 -> V_25 ,
sizeof( unsigned char ) , V_29 ) ;
if ( ! V_16 ) {
F_9 ( & V_2 -> V_20 -> V_2 , L_3 ) ;
return - V_30 ;
}
V_2 -> V_28 = V_16 ;
V_17 = F_10 ( V_14 , V_31 ) ;
if ( V_17 < 0 ) {
F_9 ( & V_2 -> V_20 -> V_2 ,
L_4 , V_17 ) ;
return V_17 ;
}
V_14 -> V_32 = V_33 ;
V_17 = F_11 ( V_14 , NULL ) ;
V_2 -> V_8 = V_9 ;
return V_17 ;
}
struct V_34 * F_12 ( struct V_1 * V_2 ,
struct V_35 * V_35 )
{
struct V_34 * V_36 ;
F_13 (cb, &dev->amthif_rd_complete_list.list, list) {
if ( V_36 -> V_14 && V_36 -> V_14 == & V_2 -> V_15 &&
V_36 -> V_37 == V_35 )
return V_36 ;
}
return NULL ;
}
int F_14 ( struct V_1 * V_2 , struct V_35 * V_35 ,
char T_1 * V_38 , T_2 V_39 , T_3 * V_40 )
{
int V_41 ;
int V_42 ;
struct V_34 * V_36 = NULL ;
struct V_13 * V_14 = V_35 -> V_43 ;
unsigned long V_44 ;
int V_18 ;
if ( ! V_14 || V_14 != & V_2 -> V_15 ) {
F_6 ( & V_2 -> V_20 -> V_2 , L_5 ) ;
return - V_45 ;
}
V_18 = F_15 ( V_2 , V_2 -> V_15 . V_22 ) ;
if ( V_18 < 0 ) {
F_6 ( & V_2 -> V_20 -> V_2 , L_6 ) ;
return - V_21 ;
}
F_6 ( & V_2 -> V_20 -> V_2 , L_7 ) ;
V_36 = F_12 ( V_2 , V_35 ) ;
if ( V_36 == NULL && V_35 -> V_46 & V_47 )
return - V_48 ;
F_6 ( & V_2 -> V_20 -> V_2 , L_8 ) ;
while ( V_36 == NULL ) {
F_16 ( & V_2 -> V_49 ) ;
V_42 = F_17 ( V_2 -> V_15 . V_50 ,
( V_36 = F_12 ( V_2 , V_35 ) ) ) ;
F_18 ( & V_2 -> V_49 ) ;
if ( V_42 )
return - V_51 ;
F_6 ( & V_2 -> V_20 -> V_2 , L_9 ) ;
}
F_6 ( & V_2 -> V_20 -> V_2 , L_10 ) ;
V_2 -> V_10 = 0 ;
if ( V_36 ) {
V_44 = V_36 -> V_52 +
F_19 ( V_53 ) ;
F_6 ( & V_2 -> V_20 -> V_2 , L_11 ,
V_44 ) ;
if ( F_20 ( V_54 , V_44 ) ) {
F_6 ( & V_2 -> V_20 -> V_2 , L_12 ) ;
F_21 ( & V_36 -> V_55 ) ;
V_41 = - V_45 ;
goto free;
}
}
if ( V_36 -> V_56 >= * V_40 && V_39 >= ( V_36 -> V_56 - * V_40 ) )
F_21 ( & V_36 -> V_55 ) ;
else if ( V_36 -> V_56 > 0 && V_36 -> V_56 <= * V_40 ) {
F_21 ( & V_36 -> V_55 ) ;
V_41 = 0 ;
goto free;
}
F_6 ( & V_2 -> V_20 -> V_2 , L_13 ,
V_36 -> V_57 . V_58 ) ;
F_6 ( & V_2 -> V_20 -> V_2 , L_14 , V_36 -> V_56 ) ;
V_39 = F_22 ( T_2 , V_39 , ( V_36 -> V_56 - * V_40 ) ) ;
if ( F_23 ( V_38 , V_36 -> V_57 . V_59 + * V_40 , V_39 ) ) {
F_6 ( & V_2 -> V_20 -> V_2 , L_15 ) ;
V_41 = - V_60 ;
} else {
V_41 = V_39 ;
if ( ( * V_40 + V_39 ) < V_36 -> V_56 ) {
* V_40 += V_39 ;
goto V_61;
}
}
free:
F_6 ( & V_2 -> V_20 -> V_2 , L_16 ) ;
* V_40 = 0 ;
F_24 ( V_36 ) ;
V_61:
return V_41 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_34 * V_36 )
{
struct V_62 V_63 ;
int V_17 ;
if ( ! V_2 || ! V_36 )
return - V_64 ;
F_6 ( & V_2 -> V_20 -> V_2 , L_17 ) ;
V_2 -> V_8 = V_65 ;
V_2 -> V_3 = V_36 ;
V_2 -> V_66 = V_36 -> V_37 ;
V_2 -> V_6 = false ;
V_2 -> V_7 = true ;
V_2 -> V_4 = V_36 -> V_67 . V_58 ;
memcpy ( V_2 -> V_28 , V_36 -> V_67 . V_59 ,
V_36 -> V_67 . V_58 ) ;
V_17 = F_26 ( & V_2 -> V_15 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_17 && F_27 ( V_2 ) ) {
V_17 = 0 ;
if ( V_36 -> V_67 . V_58 > F_28 ( V_2 ) ) {
V_63 . V_39 = F_28 ( V_2 ) ;
V_63 . V_68 = 0 ;
} else {
V_63 . V_39 = V_36 -> V_67 . V_58 ;
V_63 . V_68 = 1 ;
}
V_63 . V_69 = V_2 -> V_15 . V_70 ;
V_63 . V_71 = V_2 -> V_15 . V_22 ;
V_63 . V_72 = 0 ;
V_63 . V_73 = 0 ;
V_2 -> V_5 += V_63 . V_39 ;
V_17 = F_29 ( V_2 , & V_63 , V_2 -> V_28 ) ;
if ( V_17 )
return V_17 ;
if ( V_63 . V_68 ) {
if ( F_30 ( & V_2 -> V_15 ) )
return - V_74 ;
V_2 -> V_75 = true ;
V_2 -> V_8 = V_76 ;
F_6 ( & V_2 -> V_20 -> V_2 , L_18 ) ;
V_2 -> V_3 = V_36 ;
V_2 -> V_66 = V_36 -> V_37 ;
F_31 ( & V_36 -> V_55 , & V_2 -> V_77 . V_55 ) ;
} else {
F_6 ( & V_2 -> V_20 -> V_2 , L_19 ) ;
F_31 ( & V_36 -> V_55 , & V_2 -> V_78 . V_55 ) ;
}
} else {
F_31 ( & V_36 -> V_55 , & V_2 -> V_78 . V_55 ) ;
}
return 0 ;
}
int F_32 ( struct V_1 * V_2 , struct V_34 * V_36 )
{
int V_17 ;
if ( ! V_2 || ! V_36 )
return - V_64 ;
V_17 = F_33 ( V_36 , V_2 -> V_25 ) ;
if ( V_17 )
return V_17 ;
V_36 -> V_79 = V_80 ;
if ( ! F_34 ( & V_2 -> V_81 . V_55 ) ||
V_2 -> V_8 != V_9 ) {
F_6 ( & V_2 -> V_20 -> V_2 ,
L_20 , V_2 -> V_8 ) ;
F_6 ( & V_2 -> V_20 -> V_2 , L_21 ) ;
F_31 ( & V_36 -> V_55 , & V_2 -> V_81 . V_55 ) ;
return 0 ;
}
return F_25 ( V_2 , V_36 ) ;
}
void F_35 ( struct V_1 * V_2 )
{
struct V_34 * V_82 = NULL ;
struct V_34 * V_83 = NULL ;
int V_84 ;
if ( ! V_2 )
return;
V_2 -> V_4 = 0 ;
V_2 -> V_5 = 0 ;
V_2 -> V_6 = false ;
V_2 -> V_7 = true ;
V_2 -> V_8 = V_9 ;
V_2 -> V_10 = 0 ;
V_2 -> V_66 = NULL ;
F_6 ( & V_2 -> V_20 -> V_2 , L_22 ) ;
F_36 (pos, next, &dev->amthif_cmd_list.list, list) {
F_21 ( & V_82 -> V_55 ) ;
if ( V_82 -> V_14 && V_82 -> V_14 == & V_2 -> V_15 ) {
V_84 = F_25 ( V_2 , V_82 ) ;
if ( V_84 ) {
F_6 ( & V_2 -> V_20 -> V_2 ,
L_23 ,
V_84 ) ;
return;
}
break;
}
}
}
unsigned int F_37 ( struct V_1 * V_2 ,
struct V_35 * V_35 , T_4 * V_50 )
{
unsigned int V_85 = 0 ;
F_38 ( V_35 , & V_2 -> V_15 . V_50 , V_50 ) ;
F_18 ( & V_2 -> V_49 ) ;
if ( ! F_39 ( & V_2 -> V_15 ) ) {
V_85 = V_86 ;
} else if ( V_2 -> V_8 == V_87 &&
V_2 -> V_66 == V_35 ) {
V_85 |= ( V_88 | V_89 ) ;
F_6 ( & V_2 -> V_20 -> V_2 , L_24 ) ;
F_35 ( V_2 ) ;
}
F_16 ( & V_2 -> V_49 ) ;
return V_85 ;
}
int F_40 ( struct V_13 * V_14 , struct V_34 * V_36 ,
struct V_34 * V_90 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_62 V_63 ;
T_2 V_91 = V_2 -> V_4 - V_2 -> V_5 ;
T_5 V_92 = F_41 ( V_91 ) ;
int V_93 ;
int V_41 ;
V_41 = F_26 ( V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
if ( V_41 == 0 ) {
F_42 ( V_2 , V_14 , L_25 ) ;
return 0 ;
}
V_63 . V_69 = V_14 -> V_70 ;
V_63 . V_71 = V_14 -> V_22 ;
V_63 . V_72 = 0 ;
V_63 . V_73 = 0 ;
V_93 = F_43 ( V_2 ) ;
if ( V_93 >= V_92 ) {
V_63 . V_39 = V_91 ;
V_63 . V_68 = 1 ;
} else if ( V_93 == V_2 -> V_94 ) {
V_92 = V_93 ;
V_91 = ( V_93 * sizeof( T_5 ) ) - sizeof( struct V_62 ) ;
V_63 . V_39 = V_91 ;
V_63 . V_68 = 0 ;
} else {
return 0 ;
}
F_6 ( & V_2 -> V_20 -> V_2 , V_95 , F_44 ( & V_63 ) ) ;
V_41 = F_29 ( V_2 , & V_63 ,
V_2 -> V_28 + V_2 -> V_5 ) ;
if ( V_41 ) {
V_2 -> V_8 = V_9 ;
V_14 -> V_84 = V_41 ;
F_21 ( & V_36 -> V_55 ) ;
return V_41 ;
}
if ( F_30 ( V_14 ) )
return - V_74 ;
V_2 -> V_5 += V_63 . V_39 ;
V_14 -> V_84 = 0 ;
if ( V_63 . V_68 ) {
V_2 -> V_8 = V_76 ;
V_2 -> V_75 = true ;
V_36 -> V_56 = V_2 -> V_5 ;
V_2 -> V_3 = V_36 ;
F_45 ( & V_36 -> V_55 , & V_2 -> V_77 . V_55 ) ;
}
return 0 ;
}
int F_46 ( struct V_1 * V_2 ,
struct V_62 * V_63 ,
struct V_34 * V_96 )
{
struct V_34 * V_36 ;
unsigned char * V_97 ;
F_47 ( V_63 -> V_71 != V_2 -> V_15 . V_22 ) ;
F_47 ( V_2 -> V_8 != V_98 ) ;
V_97 = V_2 -> V_28 + V_2 -> V_5 ;
F_47 ( V_2 -> V_25 < V_2 -> V_5 + V_63 -> V_39 ) ;
F_48 ( V_2 , V_97 , V_63 -> V_39 ) ;
V_2 -> V_5 += V_63 -> V_39 ;
if ( ! V_63 -> V_68 )
return 0 ;
F_6 ( & V_2 -> V_20 -> V_2 , L_26 ,
V_63 -> V_39 ) ;
F_6 ( & V_2 -> V_20 -> V_2 , L_27 ) ;
if ( ! V_2 -> V_3 )
return - V_64 ;
V_36 = V_2 -> V_3 ;
V_2 -> V_3 = NULL ;
if ( ! V_36 -> V_14 )
return - V_64 ;
V_2 -> V_11 = 0 ;
V_36 -> V_56 = V_2 -> V_5 ;
V_36 -> V_52 = V_54 ;
if ( V_2 -> V_7 && V_36 -> V_14 == & V_2 -> V_15 ) {
F_6 ( & V_2 -> V_20 -> V_2 , L_28 ) ;
F_6 ( & V_2 -> V_20 -> V_2 , L_29 ) ;
F_31 ( & V_36 -> V_55 , & V_96 -> V_55 ) ;
}
return 0 ;
}
int F_49 ( struct V_1 * V_2 , T_6 * V_93 )
{
T_5 V_92 = F_41 ( sizeof( struct V_99 ) ) ;
if ( * V_93 < V_92 )
return - V_100 ;
* V_93 -= V_92 ;
if ( F_50 ( V_2 , & V_2 -> V_15 ) ) {
F_6 ( & V_2 -> V_20 -> V_2 , L_30 ) ;
return - V_74 ;
}
F_6 ( & V_2 -> V_20 -> V_2 , L_31 ) ;
V_2 -> V_8 = V_98 ;
V_2 -> V_75 = false ;
V_2 -> V_5 = 0 ;
V_2 -> V_4 = 0 ;
V_2 -> V_11 = V_101 ;
V_2 -> V_102 = F_51 ( V_2 ) ;
return 0 ;
}
void F_52 ( struct V_1 * V_2 , struct V_34 * V_36 )
{
if ( V_2 -> V_6 != 1 ) {
V_2 -> V_8 = V_87 ;
V_2 -> V_11 = 0 ;
memcpy ( V_36 -> V_57 . V_59 ,
V_2 -> V_28 ,
V_2 -> V_5 ) ;
F_31 ( & V_36 -> V_55 , & V_2 -> V_103 . V_55 ) ;
F_6 ( & V_2 -> V_20 -> V_2 , L_32 ) ;
V_2 -> V_10 = V_54 ;
F_6 ( & V_2 -> V_20 -> V_2 , L_33 ,
V_2 -> V_10 ) ;
} else {
F_35 ( V_2 ) ;
}
F_6 ( & V_2 -> V_20 -> V_2 , L_34 ) ;
F_53 ( & V_2 -> V_15 . V_50 ) ;
}
static bool F_54 ( struct V_1 * V_2 ,
const struct V_35 * V_35 , struct V_104 * V_105 )
{
struct V_34 * V_106 = NULL ;
struct V_34 * V_107 = NULL ;
bool V_108 = false ;
F_36 (cb_pos, cb_next, mei_cb_list, list) {
if ( V_35 == V_106 -> V_37 ) {
F_21 ( & V_106 -> V_55 ) ;
if ( V_2 -> V_3 == V_106 ) {
V_2 -> V_3 = NULL ;
F_50 ( V_2 ,
& V_2 -> V_15 ) ;
}
F_24 ( V_106 ) ;
V_106 = NULL ;
V_108 = true ;
}
}
return V_108 ;
}
static bool F_55 ( struct V_1 * V_2 , struct V_35 * V_35 )
{
bool V_108 = false ;
F_54 ( V_2 , V_35 , & V_2 -> V_81 . V_55 ) ;
if ( F_54 ( V_2 , V_35 , & V_2 -> V_103 . V_55 ) )
V_108 = true ;
F_54 ( V_2 , V_35 , & V_2 -> V_109 . V_55 ) ;
if ( F_54 ( V_2 , V_35 , & V_2 -> V_110 . V_55 ) )
V_108 = true ;
if ( F_54 ( V_2 , V_35 , & V_2 -> V_77 . V_55 ) )
V_108 = true ;
if ( F_54 ( V_2 , V_35 , & V_2 -> V_78 . V_55 ) )
V_108 = true ;
if ( V_2 -> V_3 && ! V_108 ) {
if ( V_2 -> V_3 -> V_37 == V_35 ) {
F_24 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
V_108 = true ;
}
}
return V_108 ;
}
int F_56 ( struct V_1 * V_2 , struct V_35 * V_35 )
{
if ( V_2 -> V_12 > 0 )
V_2 -> V_12 -- ;
if ( V_2 -> V_66 == V_35 &&
V_2 -> V_8 != V_9 ) {
F_6 ( & V_2 -> V_20 -> V_2 , L_35 ,
V_2 -> V_8 ) ;
V_2 -> V_6 = true ;
if ( V_2 -> V_8 == V_87 ) {
F_6 ( & V_2 -> V_20 -> V_2 , L_36 ) ;
F_35 ( V_2 ) ;
}
}
if ( F_55 ( V_2 , V_35 ) )
V_2 -> V_8 = V_9 ;
return 0 ;
}
