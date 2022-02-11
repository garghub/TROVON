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
if ( ! V_18 ) {
V_19 = - V_31 ;
goto V_32;
}
V_2 -> V_29 = V_18 ;
V_19 = F_9 ( V_14 , V_33 ) ;
if ( V_19 < 0 ) {
F_10 ( V_2 -> V_2 , L_3 , V_19 ) ;
goto V_32;
}
V_19 = F_11 ( V_14 , NULL ) ;
V_2 -> V_8 = V_9 ;
V_32:
F_12 ( V_17 ) ;
return V_19 ;
}
struct V_34 * F_13 ( struct V_1 * V_2 ,
struct V_35 * V_35 )
{
struct V_34 * V_36 ;
F_14 (cb, &dev->amthif_rd_complete_list.list, list)
if ( V_36 -> V_37 == V_35 )
return V_36 ;
return NULL ;
}
int F_15 ( struct V_1 * V_2 , struct V_35 * V_35 ,
char T_1 * V_38 , T_2 V_39 , T_3 * V_40 )
{
struct V_13 * V_14 = V_35 -> V_41 ;
struct V_34 * V_36 ;
unsigned long V_42 ;
int V_43 ;
int V_44 ;
if ( ! V_14 ) {
F_10 ( V_2 -> V_2 , L_4 ) ;
return - V_45 ;
}
F_6 ( V_2 -> V_2 , L_5 ) ;
V_36 = F_13 ( V_2 , V_35 ) ;
if ( V_36 == NULL && V_35 -> V_46 & V_47 )
return - V_48 ;
F_6 ( V_2 -> V_2 , L_6 ) ;
while ( V_36 == NULL ) {
F_16 ( & V_2 -> V_49 ) ;
V_44 = F_17 ( V_2 -> V_15 . V_50 ,
( V_36 = F_13 ( V_2 , V_35 ) ) ) ;
F_18 ( & V_2 -> V_49 ) ;
if ( V_44 )
return - V_51 ;
F_6 ( V_2 -> V_2 , L_7 ) ;
}
F_6 ( V_2 -> V_2 , L_8 ) ;
V_2 -> V_10 = 0 ;
if ( V_36 ) {
V_42 = V_36 -> V_52 +
F_19 ( V_53 ) ;
F_6 ( V_2 -> V_2 , L_9 ,
V_42 ) ;
if ( F_20 ( V_54 , V_42 ) ) {
F_6 ( V_2 -> V_2 , L_10 ) ;
F_21 ( & V_36 -> V_55 ) ;
V_43 = - V_45 ;
goto free;
}
}
if ( V_36 -> V_56 >= * V_40 && V_39 >= ( V_36 -> V_56 - * V_40 ) )
F_21 ( & V_36 -> V_55 ) ;
else if ( V_36 -> V_56 > 0 && V_36 -> V_56 <= * V_40 ) {
F_21 ( & V_36 -> V_55 ) ;
V_43 = 0 ;
goto free;
}
F_6 ( V_2 -> V_2 , L_11 ,
V_36 -> V_57 . V_58 ) ;
F_6 ( V_2 -> V_2 , L_12 , V_36 -> V_56 ) ;
V_39 = F_22 ( T_2 , V_39 , ( V_36 -> V_56 - * V_40 ) ) ;
if ( F_23 ( V_38 , V_36 -> V_57 . V_59 + * V_40 , V_39 ) ) {
F_6 ( V_2 -> V_2 , L_13 ) ;
V_43 = - V_60 ;
} else {
V_43 = V_39 ;
if ( ( * V_40 + V_39 ) < V_36 -> V_56 ) {
* V_40 += V_39 ;
goto V_32;
}
}
free:
F_6 ( V_2 -> V_2 , L_14 ) ;
* V_40 = 0 ;
F_24 ( V_36 ) ;
V_32:
return V_43 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_34 * V_36 )
{
struct V_61 V_62 ;
struct V_13 * V_14 ;
int V_19 ;
if ( ! V_2 || ! V_36 )
return - V_63 ;
F_6 ( V_2 -> V_2 , L_15 ) ;
V_2 -> V_8 = V_64 ;
V_2 -> V_3 = V_36 ;
V_2 -> V_65 = V_36 -> V_37 ;
V_2 -> V_6 = false ;
V_2 -> V_7 = true ;
V_2 -> V_4 = V_36 -> V_66 . V_58 ;
memcpy ( V_2 -> V_29 , V_36 -> V_66 . V_59 ,
V_36 -> V_66 . V_58 ) ;
V_14 = & V_2 -> V_15 ;
V_19 = F_26 ( V_14 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_19 && F_27 ( V_2 ) ) {
V_19 = 0 ;
if ( V_36 -> V_66 . V_58 > F_28 ( V_2 ) ) {
V_62 . V_39 = F_28 ( V_2 ) ;
V_62 . V_67 = 0 ;
} else {
V_62 . V_39 = V_36 -> V_66 . V_58 ;
V_62 . V_67 = 1 ;
}
V_62 . V_68 = V_14 -> V_69 ;
V_62 . V_70 = V_14 -> V_22 ;
V_62 . V_71 = 0 ;
V_62 . V_72 = 0 ;
V_2 -> V_5 += V_62 . V_39 ;
V_19 = F_29 ( V_2 , & V_62 , V_2 -> V_29 ) ;
if ( V_19 )
return V_19 ;
if ( V_62 . V_67 ) {
if ( F_30 ( V_14 ) )
return - V_73 ;
V_2 -> V_74 = true ;
V_2 -> V_8 = V_75 ;
F_6 ( V_2 -> V_2 , L_16 ) ;
V_2 -> V_3 = V_36 ;
V_2 -> V_65 = V_36 -> V_37 ;
F_31 ( & V_36 -> V_55 , & V_2 -> V_76 . V_55 ) ;
} else {
F_6 ( V_2 -> V_2 , L_17 ) ;
F_31 ( & V_36 -> V_55 , & V_2 -> V_77 . V_55 ) ;
}
} else {
F_31 ( & V_36 -> V_55 , & V_2 -> V_77 . V_55 ) ;
}
return 0 ;
}
int F_32 ( struct V_1 * V_2 , struct V_34 * V_36 )
{
int V_19 ;
if ( ! V_2 || ! V_36 )
return - V_63 ;
V_19 = F_33 ( V_36 , V_2 -> V_27 ) ;
if ( V_19 )
return V_19 ;
V_36 -> V_78 = V_79 ;
if ( ! F_34 ( & V_2 -> V_80 . V_55 ) ||
V_2 -> V_8 != V_9 ) {
F_6 ( V_2 -> V_2 ,
L_18 , V_2 -> V_8 ) ;
F_6 ( V_2 -> V_2 , L_19 ) ;
F_31 ( & V_36 -> V_55 , & V_2 -> V_80 . V_55 ) ;
return 0 ;
}
return F_25 ( V_2 , V_36 ) ;
}
void F_35 ( struct V_1 * V_2 )
{
struct V_34 * V_36 ;
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
V_36 = F_36 ( & V_2 -> V_80 . V_55 ,
F_37 ( * V_36 ) , V_55 ) ;
if ( ! V_36 )
return;
F_21 ( & V_36 -> V_55 ) ;
V_19 = F_25 ( V_2 , V_36 ) ;
if ( V_19 )
F_38 ( V_2 -> V_2 , L_21 , V_19 ) ;
}
unsigned int F_39 ( struct V_1 * V_2 ,
struct V_35 * V_35 , T_4 * V_50 )
{
unsigned int V_81 = 0 ;
F_40 ( V_35 , & V_2 -> V_15 . V_50 , V_50 ) ;
F_18 ( & V_2 -> V_49 ) ;
if ( ! F_41 ( & V_2 -> V_15 ) ) {
V_81 = V_82 ;
} else if ( V_2 -> V_8 == V_83 &&
V_2 -> V_65 == V_35 ) {
V_81 |= ( V_84 | V_85 ) ;
F_6 ( V_2 -> V_2 , L_22 ) ;
F_35 ( V_2 ) ;
}
F_16 ( & V_2 -> V_49 ) ;
return V_81 ;
}
int F_42 ( struct V_13 * V_14 , struct V_34 * V_36 ,
struct V_34 * V_86 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_61 V_62 ;
T_2 V_87 = V_2 -> V_4 - V_2 -> V_5 ;
T_5 V_88 = F_43 ( V_87 ) ;
int V_89 ;
int V_43 ;
V_43 = F_26 ( V_14 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_43 == 0 ) {
F_44 ( V_2 , V_14 , L_23 ) ;
return 0 ;
}
V_62 . V_68 = V_14 -> V_69 ;
V_62 . V_70 = V_14 -> V_22 ;
V_62 . V_71 = 0 ;
V_62 . V_72 = 0 ;
V_89 = F_45 ( V_2 ) ;
if ( V_89 >= V_88 ) {
V_62 . V_39 = V_87 ;
V_62 . V_67 = 1 ;
} else if ( V_89 == V_2 -> V_90 ) {
V_88 = V_89 ;
V_87 = ( V_89 * sizeof( T_5 ) ) - sizeof( struct V_61 ) ;
V_62 . V_39 = V_87 ;
V_62 . V_67 = 0 ;
} else {
return 0 ;
}
F_6 ( V_2 -> V_2 , V_91 , F_46 ( & V_62 ) ) ;
V_43 = F_29 ( V_2 , & V_62 ,
V_2 -> V_29 + V_2 -> V_5 ) ;
if ( V_43 ) {
V_2 -> V_8 = V_9 ;
V_14 -> V_92 = V_43 ;
F_21 ( & V_36 -> V_55 ) ;
return V_43 ;
}
if ( F_30 ( V_14 ) )
return - V_73 ;
V_2 -> V_5 += V_62 . V_39 ;
V_14 -> V_92 = 0 ;
if ( V_62 . V_67 ) {
V_2 -> V_8 = V_75 ;
V_2 -> V_74 = true ;
V_36 -> V_56 = V_2 -> V_5 ;
V_2 -> V_3 = V_36 ;
F_47 ( & V_36 -> V_55 , & V_2 -> V_76 . V_55 ) ;
}
return 0 ;
}
int F_48 ( struct V_1 * V_2 ,
struct V_61 * V_62 ,
struct V_34 * V_93 )
{
struct V_34 * V_36 ;
unsigned char * V_94 ;
F_49 ( V_62 -> V_70 != V_2 -> V_15 . V_22 ) ;
F_49 ( V_2 -> V_8 != V_95 ) ;
V_94 = V_2 -> V_29 + V_2 -> V_5 ;
F_49 ( V_2 -> V_27 < V_2 -> V_5 + V_62 -> V_39 ) ;
F_50 ( V_2 , V_94 , V_62 -> V_39 ) ;
V_2 -> V_5 += V_62 -> V_39 ;
if ( ! V_62 -> V_67 )
return 0 ;
F_6 ( V_2 -> V_2 , L_24 ,
V_62 -> V_39 ) ;
F_6 ( V_2 -> V_2 , L_25 ) ;
if ( ! V_2 -> V_3 )
return - V_63 ;
V_36 = V_2 -> V_3 ;
V_2 -> V_3 = NULL ;
V_2 -> V_11 = 0 ;
V_36 -> V_56 = V_2 -> V_5 ;
V_36 -> V_52 = V_54 ;
if ( V_2 -> V_7 ) {
F_6 ( V_2 -> V_2 , L_26 ) ;
F_6 ( V_2 -> V_2 , L_27 ) ;
F_31 ( & V_36 -> V_55 , & V_93 -> V_55 ) ;
}
return 0 ;
}
int F_51 ( struct V_1 * V_2 , T_6 * V_89 )
{
T_5 V_88 = F_43 ( sizeof( struct V_96 ) ) ;
if ( * V_89 < V_88 )
return - V_97 ;
* V_89 -= V_88 ;
if ( F_52 ( V_2 , & V_2 -> V_15 ) ) {
F_6 ( V_2 -> V_2 , L_28 ) ;
return - V_73 ;
}
F_6 ( V_2 -> V_2 , L_29 ) ;
V_2 -> V_8 = V_95 ;
V_2 -> V_74 = false ;
V_2 -> V_5 = 0 ;
V_2 -> V_4 = 0 ;
V_2 -> V_11 = V_98 ;
V_2 -> V_99 = F_53 ( V_2 ) ;
return 0 ;
}
void F_54 ( struct V_1 * V_2 , struct V_34 * V_36 )
{
if ( V_2 -> V_6 != 1 ) {
V_2 -> V_8 = V_83 ;
V_2 -> V_11 = 0 ;
memcpy ( V_36 -> V_57 . V_59 ,
V_2 -> V_29 ,
V_2 -> V_5 ) ;
F_31 ( & V_36 -> V_55 , & V_2 -> V_100 . V_55 ) ;
F_6 ( V_2 -> V_2 , L_30 ) ;
V_2 -> V_10 = V_54 ;
F_6 ( V_2 -> V_2 , L_31 ,
V_2 -> V_10 ) ;
} else {
F_35 ( V_2 ) ;
}
F_6 ( V_2 -> V_2 , L_32 ) ;
F_55 ( & V_2 -> V_15 . V_50 ) ;
}
static bool F_56 ( struct V_1 * V_2 ,
const struct V_35 * V_35 , struct V_101 * V_102 )
{
struct V_34 * V_103 = NULL ;
struct V_34 * V_104 = NULL ;
bool V_105 = false ;
F_57 (cb_pos, cb_next, mei_cb_list, list) {
if ( V_35 == V_103 -> V_37 ) {
F_21 ( & V_103 -> V_55 ) ;
if ( V_2 -> V_3 == V_103 ) {
V_2 -> V_3 = NULL ;
F_52 ( V_2 ,
& V_2 -> V_15 ) ;
}
F_24 ( V_103 ) ;
V_103 = NULL ;
V_105 = true ;
}
}
return V_105 ;
}
static bool F_58 ( struct V_1 * V_2 , struct V_35 * V_35 )
{
bool V_105 = false ;
F_56 ( V_2 , V_35 , & V_2 -> V_80 . V_55 ) ;
if ( F_56 ( V_2 , V_35 , & V_2 -> V_100 . V_55 ) )
V_105 = true ;
F_56 ( V_2 , V_35 , & V_2 -> V_106 . V_55 ) ;
if ( F_56 ( V_2 , V_35 , & V_2 -> V_107 . V_55 ) )
V_105 = true ;
if ( F_56 ( V_2 , V_35 , & V_2 -> V_76 . V_55 ) )
V_105 = true ;
if ( F_56 ( V_2 , V_35 , & V_2 -> V_77 . V_55 ) )
V_105 = true ;
if ( V_2 -> V_3 && ! V_105 ) {
if ( V_2 -> V_3 -> V_37 == V_35 ) {
F_24 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
V_105 = true ;
}
}
return V_105 ;
}
int F_59 ( struct V_1 * V_2 , struct V_35 * V_35 )
{
if ( V_2 -> V_12 > 0 )
V_2 -> V_12 -- ;
if ( V_2 -> V_65 == V_35 &&
V_2 -> V_8 != V_9 ) {
F_6 ( V_2 -> V_2 , L_33 ,
V_2 -> V_8 ) ;
V_2 -> V_6 = true ;
if ( V_2 -> V_8 == V_83 ) {
F_6 ( V_2 -> V_2 , L_34 ) ;
F_35 ( V_2 ) ;
}
}
if ( F_58 ( V_2 , V_35 ) )
V_2 -> V_8 = V_9 ;
return 0 ;
}
