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
void F_2 ( struct V_1 * V_2 )
{
int V_11 ;
unsigned char * V_12 ;
F_3 ( & V_2 -> V_13 , V_2 ) ;
V_2 -> V_13 . V_14 = V_15 ;
V_11 = F_4 ( V_2 , & V_2 -> V_13 ,
& V_16 , V_17 ) ;
if ( V_11 < 0 ) {
F_5 ( & V_2 -> V_18 -> V_2 , L_1 ) ;
return;
}
V_2 -> V_19 = V_2 -> V_20 [ V_11 ] . V_21 . V_22 ;
F_6 ( & V_2 -> V_18 -> V_2 , L_2 ,
V_2 -> V_20 [ V_11 ] . V_21 . V_22 ) ;
F_7 ( V_2 -> V_23 ) ;
V_2 -> V_23 = NULL ;
V_12 = F_8 ( V_2 -> V_19 ,
sizeof( unsigned char ) , V_24 ) ;
if ( ! V_12 ) {
F_6 ( & V_2 -> V_18 -> V_2 , L_3 ) ;
return;
}
V_2 -> V_23 = V_12 ;
if ( F_9 ( V_2 , & V_2 -> V_13 ) ) {
F_6 ( & V_2 -> V_18 -> V_2 , L_4 ) ;
V_2 -> V_13 . V_14 = V_15 ;
V_2 -> V_13 . V_25 = 0 ;
} else {
V_2 -> V_13 . V_26 = V_27 ;
}
}
struct V_28 * F_10 ( struct V_1 * V_2 ,
struct V_29 * V_29 )
{
struct V_28 * V_30 = NULL ;
struct V_28 * V_31 = NULL ;
F_11 (pos, next,
&dev->amthif_rd_complete_list.list, list) {
if ( V_30 -> V_32 && V_30 -> V_32 == & V_2 -> V_13 &&
V_30 -> V_33 == V_29 )
return V_30 ;
}
return NULL ;
}
int F_12 ( struct V_1 * V_2 , struct V_29 * V_29 ,
char T_1 * V_34 , T_2 V_35 , T_3 * V_36 )
{
int V_37 ;
int V_38 ;
struct V_28 * V_39 = NULL ;
struct V_40 * V_32 = V_29 -> V_41 ;
unsigned long V_42 ;
int V_11 ;
if ( ! V_32 || V_32 != & V_2 -> V_13 ) {
F_6 ( & V_2 -> V_18 -> V_2 , L_5 ) ;
return - V_43 ;
}
V_11 = F_13 ( V_2 , V_2 -> V_13 . V_44 ) ;
if ( V_11 < 0 ) {
F_6 ( & V_2 -> V_18 -> V_2 , L_6 ) ;
return - V_45 ;
}
F_6 ( & V_2 -> V_18 -> V_2 , L_7 ) ;
V_39 = F_10 ( V_2 , V_29 ) ;
if ( V_39 == NULL && V_29 -> V_46 & V_47 )
return - V_48 ;
F_6 ( & V_2 -> V_18 -> V_2 , L_8 ) ;
while ( V_39 == NULL ) {
F_14 ( & V_2 -> V_49 ) ;
V_38 = F_15 ( V_2 -> V_13 . V_50 ,
( V_39 = F_10 ( V_2 , V_29 ) ) ) ;
F_16 ( & V_2 -> V_49 ) ;
if ( V_38 )
return - V_51 ;
F_6 ( & V_2 -> V_18 -> V_2 , L_9 ) ;
}
F_6 ( & V_2 -> V_18 -> V_2 , L_10 ) ;
V_2 -> V_10 = 0 ;
if ( V_39 ) {
V_42 = V_39 -> V_52 +
F_17 ( V_53 ) ;
F_6 ( & V_2 -> V_18 -> V_2 , L_11 ,
V_42 ) ;
if ( F_18 ( V_54 , V_42 ) ) {
F_6 ( & V_2 -> V_18 -> V_2 , L_12 ) ;
F_19 ( & V_39 -> V_55 ) ;
V_37 = - V_43 ;
goto free;
}
}
if ( V_39 -> V_56 >= * V_36 && V_35 >= ( V_39 -> V_56 - * V_36 ) )
F_19 ( & V_39 -> V_55 ) ;
else if ( V_39 -> V_56 > 0 && V_39 -> V_56 <= * V_36 ) {
F_19 ( & V_39 -> V_55 ) ;
V_37 = 0 ;
goto free;
}
F_6 ( & V_2 -> V_18 -> V_2 , L_13 ,
V_39 -> V_57 . V_58 ) ;
F_6 ( & V_2 -> V_18 -> V_2 , L_14 , V_39 -> V_56 ) ;
V_35 = F_20 ( T_2 , V_35 , ( V_39 -> V_56 - * V_36 ) ) ;
if ( F_21 ( V_34 , V_39 -> V_57 . V_59 + * V_36 , V_35 ) )
V_37 = - V_60 ;
else {
V_37 = V_35 ;
if ( ( * V_36 + V_35 ) < V_39 -> V_56 ) {
* V_36 += V_35 ;
goto V_61;
}
}
free:
F_6 ( & V_2 -> V_18 -> V_2 , L_15 ) ;
* V_36 = 0 ;
F_22 ( V_39 ) ;
V_61:
return V_37 ;
}
static int F_23 ( struct V_1 * V_2 , struct V_28 * V_39 )
{
struct V_62 V_63 ;
int V_64 ;
if ( ! V_2 || ! V_39 )
return - V_45 ;
F_6 ( & V_2 -> V_18 -> V_2 , L_16 ) ;
V_2 -> V_8 = V_65 ;
V_2 -> V_3 = V_39 ;
V_2 -> V_66 = V_39 -> V_33 ;
V_2 -> V_6 = false ;
V_2 -> V_7 = true ;
V_2 -> V_4 = V_39 -> V_67 . V_58 ;
memcpy ( V_2 -> V_23 , V_39 -> V_67 . V_59 ,
V_39 -> V_67 . V_58 ) ;
V_64 = F_24 ( V_2 , & V_2 -> V_13 ) ;
if ( V_64 < 0 )
return V_64 ;
if ( V_64 && V_2 -> V_68 ) {
V_64 = 0 ;
V_2 -> V_68 = false ;
if ( V_39 -> V_67 . V_58 > F_25 ( V_2 ) ) {
V_63 . V_35 = F_25 ( V_2 ) ;
V_63 . V_69 = 0 ;
} else {
V_63 . V_35 = V_39 -> V_67 . V_58 ;
V_63 . V_69 = 1 ;
}
V_63 . V_70 = V_2 -> V_13 . V_25 ;
V_63 . V_71 = V_2 -> V_13 . V_44 ;
V_63 . V_72 = 0 ;
V_2 -> V_5 += V_63 . V_35 ;
if ( F_26 ( V_2 , & V_63 ,
( unsigned char * ) ( V_2 -> V_23 ) ,
V_63 . V_35 ) )
return - V_45 ;
if ( V_63 . V_69 ) {
if ( F_27 ( V_2 , & V_2 -> V_13 ) )
return - V_45 ;
V_2 -> V_73 = true ;
V_2 -> V_8 = V_74 ;
F_6 ( & V_2 -> V_18 -> V_2 , L_17 ) ;
V_2 -> V_3 = V_39 ;
V_2 -> V_66 = V_39 -> V_33 ;
F_28 ( & V_39 -> V_55 , & V_2 -> V_75 . V_55 ) ;
} else {
F_6 ( & V_2 -> V_18 -> V_2 , L_18 ) ;
F_28 ( & V_39 -> V_55 , & V_2 -> V_76 . V_55 ) ;
}
} else {
if ( ! ( V_2 -> V_68 ) )
F_6 ( & V_2 -> V_18 -> V_2 , L_19 ) ;
F_6 ( & V_2 -> V_18 -> V_2 , L_20 ) ;
F_28 ( & V_39 -> V_55 , & V_2 -> V_76 . V_55 ) ;
}
return 0 ;
}
int F_29 ( struct V_1 * V_2 , struct V_28 * V_39 )
{
int V_64 ;
if ( ! V_2 || ! V_39 )
return - V_45 ;
V_64 = F_30 ( V_39 , V_2 -> V_19 ) ;
if ( V_64 )
return V_64 ;
V_39 -> V_77 = V_78 ;
if ( ! F_31 ( & V_2 -> V_79 . V_55 ) ||
V_2 -> V_8 != V_9 ) {
F_6 ( & V_2 -> V_18 -> V_2 ,
L_21 , V_2 -> V_8 ) ;
F_6 ( & V_2 -> V_18 -> V_2 , L_22 ) ;
F_28 ( & V_39 -> V_55 , & V_2 -> V_79 . V_55 ) ;
return 0 ;
}
return F_23 ( V_2 , V_39 ) ;
}
void F_32 ( struct V_1 * V_2 )
{
struct V_28 * V_30 = NULL ;
struct V_28 * V_31 = NULL ;
int V_80 ;
if ( ! V_2 )
return;
V_2 -> V_4 = 0 ;
V_2 -> V_5 = 0 ;
V_2 -> V_6 = false ;
V_2 -> V_7 = true ;
V_2 -> V_8 = V_9 ;
V_2 -> V_10 = 0 ;
V_2 -> V_66 = NULL ;
F_6 ( & V_2 -> V_18 -> V_2 , L_23 ) ;
F_11 (pos, next, &dev->amthif_cmd_list.list, list) {
F_19 ( & V_30 -> V_55 ) ;
if ( V_30 -> V_32 && V_30 -> V_32 == & V_2 -> V_13 ) {
V_80 = F_23 ( V_2 , V_30 ) ;
if ( V_80 ) {
F_6 ( & V_2 -> V_18 -> V_2 ,
L_24 ,
V_80 ) ;
return;
}
break;
}
}
}
unsigned int F_33 ( struct V_1 * V_2 ,
struct V_29 * V_29 , T_4 * V_50 )
{
unsigned int V_81 = 0 ;
F_14 ( & V_2 -> V_49 ) ;
F_34 ( V_29 , & V_2 -> V_13 . V_50 , V_50 ) ;
F_16 ( & V_2 -> V_49 ) ;
if ( V_2 -> V_8 == V_82 &&
V_2 -> V_66 == V_29 ) {
V_81 |= ( V_83 | V_84 ) ;
F_6 ( & V_2 -> V_18 -> V_2 , L_25 ) ;
F_32 ( V_2 ) ;
}
return V_81 ;
}
int F_35 ( struct V_1 * V_2 , T_5 * V_85 ,
struct V_28 * V_39 , struct V_28 * V_86 )
{
struct V_62 * V_63 ;
struct V_40 * V_32 = V_39 -> V_32 ;
T_2 V_87 = V_2 -> V_4 - V_2 -> V_5 ;
T_2 V_88 = F_36 ( V_87 ) ;
V_63 = (struct V_62 * ) & V_2 -> V_89 [ 0 ] ;
V_63 -> V_70 = V_32 -> V_25 ;
V_63 -> V_71 = V_32 -> V_44 ;
V_63 -> V_72 = 0 ;
if ( * V_85 >= V_88 ) {
V_63 -> V_35 = V_87 ;
V_63 -> V_69 = 1 ;
} else if ( * V_85 == V_2 -> V_90 ) {
V_88 = * V_85 ;
V_87 = ( * V_85 * sizeof( V_91 ) ) - sizeof( struct V_62 ) ;
V_63 -> V_35 = V_87 ;
V_63 -> V_69 = 0 ;
} else {
return 0 ;
}
F_6 ( & V_2 -> V_18 -> V_2 , L_26 ,
V_63 -> V_35 , V_63 -> V_69 ) ;
* V_85 -= V_88 ;
if ( F_26 ( V_2 , V_63 ,
V_2 -> V_23 + V_2 -> V_5 ,
V_63 -> V_35 ) ) {
V_2 -> V_8 = V_9 ;
V_32 -> V_80 = - V_45 ;
F_19 ( & V_39 -> V_55 ) ;
return - V_45 ;
}
if ( F_27 ( V_2 , V_32 ) )
return - V_45 ;
V_2 -> V_5 += V_63 -> V_35 ;
V_32 -> V_80 = 0 ;
if ( V_63 -> V_69 ) {
V_2 -> V_8 = V_74 ;
V_2 -> V_73 = true ;
V_39 -> V_56 = V_2 -> V_5 ;
V_2 -> V_3 = V_39 ;
F_37 ( & V_39 -> V_55 , & V_2 -> V_75 . V_55 ) ;
}
return 0 ;
}
int F_38 ( struct V_28 * V_92 ,
struct V_1 * V_2 , struct V_62 * V_63 )
{
struct V_28 * V_39 ;
unsigned char * V_93 ;
F_39 ( V_63 -> V_71 != V_2 -> V_13 . V_44 ) ;
F_39 ( V_2 -> V_8 != V_94 ) ;
V_93 = V_2 -> V_23 + V_2 -> V_5 ;
F_39 ( V_2 -> V_19 < V_2 -> V_5 + V_63 -> V_35 ) ;
F_40 ( V_2 , V_93 , V_63 -> V_35 ) ;
V_2 -> V_5 += V_63 -> V_35 ;
if ( ! V_63 -> V_69 )
return 0 ;
F_6 ( & V_2 -> V_18 -> V_2 ,
L_27 ,
V_63 -> V_35 ) ;
F_6 ( & V_2 -> V_18 -> V_2 , L_28 ) ;
if ( ! V_2 -> V_3 )
return - V_45 ;
V_39 = V_2 -> V_3 ;
V_2 -> V_3 = NULL ;
if ( ! V_39 -> V_32 )
return - V_45 ;
V_2 -> V_95 = 0 ;
V_39 -> V_56 = V_2 -> V_5 ;
V_39 -> V_52 = V_54 ;
if ( V_2 -> V_7 && V_39 -> V_32 == & V_2 -> V_13 ) {
F_6 ( & V_2 -> V_18 -> V_2 , L_29 ) ;
F_6 ( & V_2 -> V_18 -> V_2 , L_30 ) ;
F_28 ( & V_39 -> V_55 , & V_92 -> V_55 ) ;
}
return 0 ;
}
int F_41 ( struct V_1 * V_2 , T_5 * V_85 )
{
if ( ( ( * V_85 ) * sizeof( V_91 ) ) < ( sizeof( struct V_62 )
+ sizeof( struct V_96 ) ) ) {
return - V_97 ;
}
* V_85 -= F_36 ( sizeof( struct V_96 ) ) ;
if ( F_42 ( V_2 , & V_2 -> V_13 ) ) {
F_6 ( & V_2 -> V_18 -> V_2 , L_31 ) ;
return - V_98 ;
}
F_6 ( & V_2 -> V_18 -> V_2 , L_32 ) ;
V_2 -> V_8 = V_94 ;
V_2 -> V_73 = false ;
V_2 -> V_5 = 0 ;
V_2 -> V_4 = 0 ;
V_2 -> V_95 = V_99 ;
V_2 -> V_68 = F_43 ( V_2 ) ;
return 0 ;
}
void F_44 ( struct V_1 * V_2 , struct V_28 * V_39 )
{
if ( V_2 -> V_6 != 1 ) {
V_2 -> V_8 = V_82 ;
V_2 -> V_95 = 0 ;
memcpy ( V_39 -> V_57 . V_59 ,
V_2 -> V_23 ,
V_2 -> V_5 ) ;
F_28 ( & V_39 -> V_55 , & V_2 -> V_100 . V_55 ) ;
F_6 ( & V_2 -> V_18 -> V_2 , L_33 ) ;
V_2 -> V_10 = V_54 ;
F_6 ( & V_2 -> V_18 -> V_2 , L_34 ,
V_2 -> V_10 ) ;
} else {
F_32 ( V_2 ) ;
}
F_6 ( & V_2 -> V_18 -> V_2 , L_35 ) ;
F_45 ( & V_2 -> V_13 . V_50 ) ;
}
static bool F_46 ( struct V_1 * V_2 ,
const struct V_29 * V_29 , struct V_101 * V_102 )
{
struct V_28 * V_103 = NULL ;
struct V_28 * V_104 = NULL ;
bool V_105 = false ;
F_11 (cb_pos, cb_next, mei_cb_list, list) {
if ( V_29 == V_103 -> V_33 ) {
F_19 ( & V_103 -> V_55 ) ;
if ( V_2 -> V_3 == V_103 ) {
V_2 -> V_3 = NULL ;
F_42 ( V_2 , & V_2 -> V_13 ) ;
}
F_22 ( V_103 ) ;
V_103 = NULL ;
V_105 = true ;
}
}
return V_105 ;
}
static bool F_47 ( struct V_1 * V_2 , struct V_29 * V_29 )
{
bool V_105 = false ;
F_46 ( V_2 , V_29 , & V_2 -> V_79 . V_55 ) ;
if ( F_46 ( V_2 , V_29 , & V_2 -> V_100 . V_55 ) )
V_105 = true ;
F_46 ( V_2 , V_29 , & V_2 -> V_106 . V_55 ) ;
if ( F_46 ( V_2 , V_29 , & V_2 -> V_107 . V_55 ) )
V_105 = true ;
if ( F_46 ( V_2 , V_29 , & V_2 -> V_75 . V_55 ) )
V_105 = true ;
if ( F_46 ( V_2 , V_29 , & V_2 -> V_76 . V_55 ) )
V_105 = true ;
if ( V_2 -> V_3 && ! V_105 ) {
if ( V_2 -> V_3 -> V_33 == V_29 ) {
F_22 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
V_105 = true ;
}
}
return V_105 ;
}
int F_48 ( struct V_1 * V_2 , struct V_29 * V_29 )
{
if ( V_2 -> V_108 > 0 )
V_2 -> V_108 -- ;
if ( V_2 -> V_66 == V_29 &&
V_2 -> V_8 != V_9 ) {
F_6 ( & V_2 -> V_18 -> V_2 , L_36 ,
V_2 -> V_8 ) ;
V_2 -> V_6 = true ;
if ( V_2 -> V_8 == V_82 ) {
F_6 ( & V_2 -> V_18 -> V_2 , L_37 ) ;
F_32 ( V_2 ) ;
}
}
if ( F_47 ( V_2 , V_29 ) )
V_2 -> V_8 = V_9 ;
return 0 ;
}
