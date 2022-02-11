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
struct V_16 * V_17 ;
unsigned char * V_18 ;
int V_19 ;
V_2 -> V_8 = V_9 ;
F_3 ( V_14 , V_2 ) ;
V_17 = F_4 ( V_2 , & V_20 ) ;
if ( ! V_17 ) {
F_5 ( V_2 -> V_2 , L_1 ) ;
return - V_21 ;
}
V_14 -> V_22 = V_17 -> V_23 ;
V_14 -> V_24 = V_17 -> V_25 . V_26 ;
V_2 -> V_27 = V_17 -> V_25 . V_28 ;
F_6 ( V_2 -> V_2 , L_2 , V_2 -> V_27 ) ;
F_7 ( V_2 -> V_29 ) ;
V_2 -> V_29 = NULL ;
V_18 = F_8 ( V_2 -> V_27 ,
sizeof( unsigned char ) , V_30 ) ;
if ( ! V_18 )
return - V_31 ;
V_2 -> V_29 = V_18 ;
V_19 = F_9 ( V_14 , V_32 ) ;
if ( V_19 < 0 ) {
F_10 ( V_2 -> V_2 ,
L_3 , V_19 ) ;
return V_19 ;
}
V_19 = F_11 ( V_14 , NULL ) ;
V_2 -> V_8 = V_9 ;
return V_19 ;
}
struct V_33 * F_12 ( struct V_1 * V_2 ,
struct V_34 * V_34 )
{
struct V_33 * V_35 ;
F_13 (cb, &dev->amthif_rd_complete_list.list, list)
if ( V_35 -> V_36 == V_34 )
return V_35 ;
return NULL ;
}
int F_14 ( struct V_1 * V_2 , struct V_34 * V_34 ,
char T_1 * V_37 , T_2 V_38 , T_3 * V_39 )
{
struct V_13 * V_14 = V_34 -> V_40 ;
struct V_33 * V_35 ;
unsigned long V_41 ;
int V_42 ;
int V_43 ;
if ( ! V_14 ) {
F_10 ( V_2 -> V_2 , L_4 ) ;
return - V_44 ;
}
F_6 ( V_2 -> V_2 , L_5 ) ;
V_35 = F_12 ( V_2 , V_34 ) ;
if ( V_35 == NULL && V_34 -> V_45 & V_46 )
return - V_47 ;
F_6 ( V_2 -> V_2 , L_6 ) ;
while ( V_35 == NULL ) {
F_15 ( & V_2 -> V_48 ) ;
V_43 = F_16 ( V_2 -> V_15 . V_49 ,
( V_35 = F_12 ( V_2 , V_34 ) ) ) ;
F_17 ( & V_2 -> V_48 ) ;
if ( V_43 )
return - V_50 ;
F_6 ( V_2 -> V_2 , L_7 ) ;
}
F_6 ( V_2 -> V_2 , L_8 ) ;
V_2 -> V_10 = 0 ;
if ( V_35 ) {
V_41 = V_35 -> V_51 +
F_18 ( V_52 ) ;
F_6 ( V_2 -> V_2 , L_9 ,
V_41 ) ;
if ( F_19 ( V_53 , V_41 ) ) {
F_6 ( V_2 -> V_2 , L_10 ) ;
F_20 ( & V_35 -> V_54 ) ;
V_42 = - V_44 ;
goto free;
}
}
if ( V_35 -> V_55 >= * V_39 && V_38 >= ( V_35 -> V_55 - * V_39 ) )
F_20 ( & V_35 -> V_54 ) ;
else if ( V_35 -> V_55 > 0 && V_35 -> V_55 <= * V_39 ) {
F_20 ( & V_35 -> V_54 ) ;
V_42 = 0 ;
goto free;
}
F_6 ( V_2 -> V_2 , L_11 ,
V_35 -> V_56 . V_57 ) ;
F_6 ( V_2 -> V_2 , L_12 , V_35 -> V_55 ) ;
V_38 = F_21 ( T_2 , V_38 , ( V_35 -> V_55 - * V_39 ) ) ;
if ( F_22 ( V_37 , V_35 -> V_56 . V_58 + * V_39 , V_38 ) ) {
F_6 ( V_2 -> V_2 , L_13 ) ;
V_42 = - V_59 ;
} else {
V_42 = V_38 ;
if ( ( * V_39 + V_38 ) < V_35 -> V_55 ) {
* V_39 += V_38 ;
goto V_60;
}
}
free:
F_6 ( V_2 -> V_2 , L_14 ) ;
* V_39 = 0 ;
F_23 ( V_35 ) ;
V_60:
return V_42 ;
}
static int F_24 ( struct V_1 * V_2 , struct V_33 * V_35 )
{
struct V_61 V_62 ;
struct V_13 * V_14 ;
int V_19 ;
if ( ! V_2 || ! V_35 )
return - V_63 ;
F_6 ( V_2 -> V_2 , L_15 ) ;
V_2 -> V_8 = V_64 ;
V_2 -> V_3 = V_35 ;
V_2 -> V_65 = V_35 -> V_36 ;
V_2 -> V_6 = false ;
V_2 -> V_7 = true ;
V_2 -> V_4 = V_35 -> V_66 . V_57 ;
memcpy ( V_2 -> V_29 , V_35 -> V_66 . V_58 ,
V_35 -> V_66 . V_57 ) ;
V_14 = & V_2 -> V_15 ;
V_19 = F_25 ( V_14 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_19 && F_26 ( V_2 ) ) {
V_19 = 0 ;
if ( V_35 -> V_66 . V_57 > F_27 ( V_2 ) ) {
V_62 . V_38 = F_27 ( V_2 ) ;
V_62 . V_67 = 0 ;
} else {
V_62 . V_38 = V_35 -> V_66 . V_57 ;
V_62 . V_67 = 1 ;
}
V_62 . V_68 = V_14 -> V_69 ;
V_62 . V_70 = V_14 -> V_22 ;
V_62 . V_71 = 0 ;
V_62 . V_72 = 0 ;
V_2 -> V_5 += V_62 . V_38 ;
V_19 = F_28 ( V_2 , & V_62 , V_2 -> V_29 ) ;
if ( V_19 )
return V_19 ;
if ( V_62 . V_67 ) {
if ( F_29 ( V_14 ) )
return - V_73 ;
V_2 -> V_74 = true ;
V_2 -> V_8 = V_75 ;
F_6 ( V_2 -> V_2 , L_16 ) ;
V_2 -> V_3 = V_35 ;
V_2 -> V_65 = V_35 -> V_36 ;
F_30 ( & V_35 -> V_54 , & V_2 -> V_76 . V_54 ) ;
} else {
F_6 ( V_2 -> V_2 , L_17 ) ;
F_30 ( & V_35 -> V_54 , & V_2 -> V_77 . V_54 ) ;
}
} else {
F_30 ( & V_35 -> V_54 , & V_2 -> V_77 . V_54 ) ;
}
return 0 ;
}
int F_31 ( struct V_1 * V_2 , struct V_33 * V_35 )
{
int V_19 ;
if ( ! V_2 || ! V_35 )
return - V_63 ;
V_19 = F_32 ( V_35 , V_2 -> V_27 ) ;
if ( V_19 )
return V_19 ;
V_35 -> V_78 = V_79 ;
if ( ! F_33 ( & V_2 -> V_80 . V_54 ) ||
V_2 -> V_8 != V_9 ) {
F_6 ( V_2 -> V_2 ,
L_18 , V_2 -> V_8 ) ;
F_6 ( V_2 -> V_2 , L_19 ) ;
F_30 ( & V_35 -> V_54 , & V_2 -> V_80 . V_54 ) ;
return 0 ;
}
return F_24 ( V_2 , V_35 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
struct V_33 * V_35 ;
int V_19 ;
if ( ! V_2 )
return;
V_2 -> V_4 = 0 ;
V_2 -> V_5 = 0 ;
V_2 -> V_6 = false ;
V_2 -> V_7 = true ;
V_2 -> V_8 = V_9 ;
V_2 -> V_10 = 0 ;
V_2 -> V_65 = NULL ;
F_6 ( V_2 -> V_2 , L_20 ) ;
V_35 = F_35 ( & V_2 -> V_80 . V_54 ,
F_36 ( * V_35 ) , V_54 ) ;
if ( ! V_35 )
return;
F_20 ( & V_35 -> V_54 ) ;
V_19 = F_24 ( V_2 , V_35 ) ;
if ( V_19 )
F_37 ( V_2 -> V_2 , L_21 , V_19 ) ;
}
unsigned int F_38 ( struct V_1 * V_2 ,
struct V_34 * V_34 , T_4 * V_49 )
{
unsigned int V_81 = 0 ;
F_39 ( V_34 , & V_2 -> V_15 . V_49 , V_49 ) ;
F_17 ( & V_2 -> V_48 ) ;
if ( ! F_40 ( & V_2 -> V_15 ) ) {
V_81 = V_82 ;
} else if ( V_2 -> V_8 == V_83 &&
V_2 -> V_65 == V_34 ) {
V_81 |= ( V_84 | V_85 ) ;
F_6 ( V_2 -> V_2 , L_22 ) ;
F_34 ( V_2 ) ;
}
F_15 ( & V_2 -> V_48 ) ;
return V_81 ;
}
int F_41 ( struct V_13 * V_14 , struct V_33 * V_35 ,
struct V_33 * V_86 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_61 V_62 ;
T_2 V_87 = V_2 -> V_4 - V_2 -> V_5 ;
T_5 V_88 = F_42 ( V_87 ) ;
int V_89 ;
int V_42 ;
V_42 = F_25 ( V_14 ) ;
if ( V_42 < 0 )
return V_42 ;
if ( V_42 == 0 ) {
F_43 ( V_2 , V_14 , L_23 ) ;
return 0 ;
}
V_62 . V_68 = V_14 -> V_69 ;
V_62 . V_70 = V_14 -> V_22 ;
V_62 . V_71 = 0 ;
V_62 . V_72 = 0 ;
V_89 = F_44 ( V_2 ) ;
if ( V_89 >= V_88 ) {
V_62 . V_38 = V_87 ;
V_62 . V_67 = 1 ;
} else if ( V_89 == V_2 -> V_90 ) {
V_88 = V_89 ;
V_87 = ( V_89 * sizeof( T_5 ) ) - sizeof( struct V_61 ) ;
V_62 . V_38 = V_87 ;
V_62 . V_67 = 0 ;
} else {
return 0 ;
}
F_6 ( V_2 -> V_2 , V_91 , F_45 ( & V_62 ) ) ;
V_42 = F_28 ( V_2 , & V_62 ,
V_2 -> V_29 + V_2 -> V_5 ) ;
if ( V_42 ) {
V_2 -> V_8 = V_9 ;
V_14 -> V_92 = V_42 ;
F_20 ( & V_35 -> V_54 ) ;
return V_42 ;
}
if ( F_29 ( V_14 ) )
return - V_73 ;
V_2 -> V_5 += V_62 . V_38 ;
V_14 -> V_92 = 0 ;
if ( V_62 . V_67 ) {
V_2 -> V_8 = V_75 ;
V_2 -> V_74 = true ;
V_35 -> V_55 = V_2 -> V_5 ;
V_2 -> V_3 = V_35 ;
F_46 ( & V_35 -> V_54 , & V_2 -> V_76 . V_54 ) ;
}
return 0 ;
}
int F_47 ( struct V_1 * V_2 ,
struct V_61 * V_62 ,
struct V_33 * V_93 )
{
struct V_33 * V_35 ;
unsigned char * V_94 ;
F_48 ( V_62 -> V_70 != V_2 -> V_15 . V_22 ) ;
F_48 ( V_2 -> V_8 != V_95 ) ;
V_94 = V_2 -> V_29 + V_2 -> V_5 ;
F_48 ( V_2 -> V_27 < V_2 -> V_5 + V_62 -> V_38 ) ;
F_49 ( V_2 , V_94 , V_62 -> V_38 ) ;
V_2 -> V_5 += V_62 -> V_38 ;
if ( ! V_62 -> V_67 )
return 0 ;
F_6 ( V_2 -> V_2 , L_24 ,
V_62 -> V_38 ) ;
F_6 ( V_2 -> V_2 , L_25 ) ;
if ( ! V_2 -> V_3 )
return - V_63 ;
V_35 = V_2 -> V_3 ;
V_2 -> V_3 = NULL ;
V_2 -> V_11 = 0 ;
V_35 -> V_55 = V_2 -> V_5 ;
V_35 -> V_51 = V_53 ;
if ( V_2 -> V_7 ) {
F_6 ( V_2 -> V_2 , L_26 ) ;
F_6 ( V_2 -> V_2 , L_27 ) ;
F_30 ( & V_35 -> V_54 , & V_93 -> V_54 ) ;
}
return 0 ;
}
int F_50 ( struct V_1 * V_2 , T_6 * V_89 )
{
T_5 V_88 = F_42 ( sizeof( struct V_96 ) ) ;
if ( * V_89 < V_88 )
return - V_97 ;
* V_89 -= V_88 ;
if ( F_51 ( V_2 , & V_2 -> V_15 ) ) {
F_6 ( V_2 -> V_2 , L_28 ) ;
return - V_73 ;
}
F_6 ( V_2 -> V_2 , L_29 ) ;
V_2 -> V_8 = V_95 ;
V_2 -> V_74 = false ;
V_2 -> V_5 = 0 ;
V_2 -> V_4 = 0 ;
V_2 -> V_11 = V_98 ;
V_2 -> V_99 = F_52 ( V_2 ) ;
return 0 ;
}
void F_53 ( struct V_1 * V_2 , struct V_33 * V_35 )
{
if ( V_2 -> V_6 != 1 ) {
V_2 -> V_8 = V_83 ;
V_2 -> V_11 = 0 ;
memcpy ( V_35 -> V_56 . V_58 ,
V_2 -> V_29 ,
V_2 -> V_5 ) ;
F_30 ( & V_35 -> V_54 , & V_2 -> V_100 . V_54 ) ;
F_6 ( V_2 -> V_2 , L_30 ) ;
V_2 -> V_10 = V_53 ;
F_6 ( V_2 -> V_2 , L_31 ,
V_2 -> V_10 ) ;
} else {
F_34 ( V_2 ) ;
}
F_6 ( V_2 -> V_2 , L_32 ) ;
F_54 ( & V_2 -> V_15 . V_49 ) ;
}
static bool F_55 ( struct V_1 * V_2 ,
const struct V_34 * V_34 , struct V_101 * V_102 )
{
struct V_33 * V_103 = NULL ;
struct V_33 * V_104 = NULL ;
bool V_105 = false ;
F_56 (cb_pos, cb_next, mei_cb_list, list) {
if ( V_34 == V_103 -> V_36 ) {
F_20 ( & V_103 -> V_54 ) ;
if ( V_2 -> V_3 == V_103 ) {
V_2 -> V_3 = NULL ;
F_51 ( V_2 ,
& V_2 -> V_15 ) ;
}
F_23 ( V_103 ) ;
V_103 = NULL ;
V_105 = true ;
}
}
return V_105 ;
}
static bool F_57 ( struct V_1 * V_2 , struct V_34 * V_34 )
{
bool V_105 = false ;
F_55 ( V_2 , V_34 , & V_2 -> V_80 . V_54 ) ;
if ( F_55 ( V_2 , V_34 , & V_2 -> V_100 . V_54 ) )
V_105 = true ;
F_55 ( V_2 , V_34 , & V_2 -> V_106 . V_54 ) ;
if ( F_55 ( V_2 , V_34 , & V_2 -> V_107 . V_54 ) )
V_105 = true ;
if ( F_55 ( V_2 , V_34 , & V_2 -> V_76 . V_54 ) )
V_105 = true ;
if ( F_55 ( V_2 , V_34 , & V_2 -> V_77 . V_54 ) )
V_105 = true ;
if ( V_2 -> V_3 && ! V_105 ) {
if ( V_2 -> V_3 -> V_36 == V_34 ) {
F_23 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
V_105 = true ;
}
}
return V_105 ;
}
int F_58 ( struct V_1 * V_2 , struct V_34 * V_34 )
{
if ( V_2 -> V_12 > 0 )
V_2 -> V_12 -- ;
if ( V_2 -> V_65 == V_34 &&
V_2 -> V_8 != V_9 ) {
F_6 ( V_2 -> V_2 , L_33 ,
V_2 -> V_8 ) ;
V_2 -> V_6 = true ;
if ( V_2 -> V_8 == V_83 ) {
F_6 ( V_2 -> V_2 , L_34 ) ;
F_34 ( V_2 ) ;
}
}
if ( F_57 ( V_2 , V_34 ) )
V_2 -> V_8 = V_9 ;
return 0 ;
}
