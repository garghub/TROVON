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
V_17 = F_11 ( V_14 , NULL ) ;
V_2 -> V_8 = V_9 ;
return V_17 ;
}
struct V_32 * F_12 ( struct V_1 * V_2 ,
struct V_33 * V_33 )
{
struct V_32 * V_34 ;
F_13 (cb, &dev->amthif_rd_complete_list.list, list) {
if ( V_34 -> V_14 && V_34 -> V_14 == & V_2 -> V_15 &&
V_34 -> V_35 == V_33 )
return V_34 ;
}
return NULL ;
}
int F_14 ( struct V_1 * V_2 , struct V_33 * V_33 ,
char T_1 * V_36 , T_2 V_37 , T_3 * V_38 )
{
int V_39 ;
int V_40 ;
struct V_32 * V_34 = NULL ;
struct V_13 * V_14 = V_33 -> V_41 ;
unsigned long V_42 ;
int V_18 ;
if ( ! V_14 || V_14 != & V_2 -> V_15 ) {
F_6 ( & V_2 -> V_20 -> V_2 , L_5 ) ;
return - V_43 ;
}
V_18 = F_15 ( V_2 , V_2 -> V_15 . V_22 ) ;
if ( V_18 < 0 ) {
F_6 ( & V_2 -> V_20 -> V_2 , L_6 ) ;
return - V_21 ;
}
F_6 ( & V_2 -> V_20 -> V_2 , L_7 ) ;
V_34 = F_12 ( V_2 , V_33 ) ;
if ( V_34 == NULL && V_33 -> V_44 & V_45 )
return - V_46 ;
F_6 ( & V_2 -> V_20 -> V_2 , L_8 ) ;
while ( V_34 == NULL ) {
F_16 ( & V_2 -> V_47 ) ;
V_40 = F_17 ( V_2 -> V_15 . V_48 ,
( V_34 = F_12 ( V_2 , V_33 ) ) ) ;
F_18 ( & V_2 -> V_47 ) ;
if ( V_40 )
return - V_49 ;
F_6 ( & V_2 -> V_20 -> V_2 , L_9 ) ;
}
F_6 ( & V_2 -> V_20 -> V_2 , L_10 ) ;
V_2 -> V_10 = 0 ;
if ( V_34 ) {
V_42 = V_34 -> V_50 +
F_19 ( V_51 ) ;
F_6 ( & V_2 -> V_20 -> V_2 , L_11 ,
V_42 ) ;
if ( F_20 ( V_52 , V_42 ) ) {
F_6 ( & V_2 -> V_20 -> V_2 , L_12 ) ;
F_21 ( & V_34 -> V_53 ) ;
V_39 = - V_43 ;
goto free;
}
}
if ( V_34 -> V_54 >= * V_38 && V_37 >= ( V_34 -> V_54 - * V_38 ) )
F_21 ( & V_34 -> V_53 ) ;
else if ( V_34 -> V_54 > 0 && V_34 -> V_54 <= * V_38 ) {
F_21 ( & V_34 -> V_53 ) ;
V_39 = 0 ;
goto free;
}
F_6 ( & V_2 -> V_20 -> V_2 , L_13 ,
V_34 -> V_55 . V_56 ) ;
F_6 ( & V_2 -> V_20 -> V_2 , L_14 , V_34 -> V_54 ) ;
V_37 = F_22 ( T_2 , V_37 , ( V_34 -> V_54 - * V_38 ) ) ;
if ( F_23 ( V_36 , V_34 -> V_55 . V_57 + * V_38 , V_37 ) ) {
F_6 ( & V_2 -> V_20 -> V_2 , L_15 ) ;
V_39 = - V_58 ;
} else {
V_39 = V_37 ;
if ( ( * V_38 + V_37 ) < V_34 -> V_54 ) {
* V_38 += V_37 ;
goto V_59;
}
}
free:
F_6 ( & V_2 -> V_20 -> V_2 , L_16 ) ;
* V_38 = 0 ;
F_24 ( V_34 ) ;
V_59:
return V_39 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_32 * V_34 )
{
struct V_60 V_61 ;
int V_17 ;
if ( ! V_2 || ! V_34 )
return - V_62 ;
F_6 ( & V_2 -> V_20 -> V_2 , L_17 ) ;
V_2 -> V_8 = V_63 ;
V_2 -> V_3 = V_34 ;
V_2 -> V_64 = V_34 -> V_35 ;
V_2 -> V_6 = false ;
V_2 -> V_7 = true ;
V_2 -> V_4 = V_34 -> V_65 . V_56 ;
memcpy ( V_2 -> V_28 , V_34 -> V_65 . V_57 ,
V_34 -> V_65 . V_56 ) ;
V_17 = F_26 ( & V_2 -> V_15 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_17 && F_27 ( V_2 ) ) {
V_17 = 0 ;
if ( V_34 -> V_65 . V_56 > F_28 ( V_2 ) ) {
V_61 . V_37 = F_28 ( V_2 ) ;
V_61 . V_66 = 0 ;
} else {
V_61 . V_37 = V_34 -> V_65 . V_56 ;
V_61 . V_66 = 1 ;
}
V_61 . V_67 = V_2 -> V_15 . V_68 ;
V_61 . V_69 = V_2 -> V_15 . V_22 ;
V_61 . V_70 = 0 ;
V_61 . V_71 = 0 ;
V_2 -> V_5 += V_61 . V_37 ;
V_17 = F_29 ( V_2 , & V_61 , V_2 -> V_28 ) ;
if ( V_17 )
return V_17 ;
if ( V_61 . V_66 ) {
if ( F_30 ( & V_2 -> V_15 ) )
return - V_72 ;
V_2 -> V_73 = true ;
V_2 -> V_8 = V_74 ;
F_6 ( & V_2 -> V_20 -> V_2 , L_18 ) ;
V_2 -> V_3 = V_34 ;
V_2 -> V_64 = V_34 -> V_35 ;
F_31 ( & V_34 -> V_53 , & V_2 -> V_75 . V_53 ) ;
} else {
F_6 ( & V_2 -> V_20 -> V_2 , L_19 ) ;
F_31 ( & V_34 -> V_53 , & V_2 -> V_76 . V_53 ) ;
}
} else {
F_31 ( & V_34 -> V_53 , & V_2 -> V_76 . V_53 ) ;
}
return 0 ;
}
int F_32 ( struct V_1 * V_2 , struct V_32 * V_34 )
{
int V_17 ;
if ( ! V_2 || ! V_34 )
return - V_62 ;
V_17 = F_33 ( V_34 , V_2 -> V_25 ) ;
if ( V_17 )
return V_17 ;
V_34 -> V_77 = V_78 ;
if ( ! F_34 ( & V_2 -> V_79 . V_53 ) ||
V_2 -> V_8 != V_9 ) {
F_6 ( & V_2 -> V_20 -> V_2 ,
L_20 , V_2 -> V_8 ) ;
F_6 ( & V_2 -> V_20 -> V_2 , L_21 ) ;
F_31 ( & V_34 -> V_53 , & V_2 -> V_79 . V_53 ) ;
return 0 ;
}
return F_25 ( V_2 , V_34 ) ;
}
void F_35 ( struct V_1 * V_2 )
{
struct V_32 * V_80 = NULL ;
struct V_32 * V_81 = NULL ;
int V_82 ;
if ( ! V_2 )
return;
V_2 -> V_4 = 0 ;
V_2 -> V_5 = 0 ;
V_2 -> V_6 = false ;
V_2 -> V_7 = true ;
V_2 -> V_8 = V_9 ;
V_2 -> V_10 = 0 ;
V_2 -> V_64 = NULL ;
F_6 ( & V_2 -> V_20 -> V_2 , L_22 ) ;
F_36 (pos, next, &dev->amthif_cmd_list.list, list) {
F_21 ( & V_80 -> V_53 ) ;
if ( V_80 -> V_14 && V_80 -> V_14 == & V_2 -> V_15 ) {
V_82 = F_25 ( V_2 , V_80 ) ;
if ( V_82 ) {
F_6 ( & V_2 -> V_20 -> V_2 ,
L_23 ,
V_82 ) ;
return;
}
break;
}
}
}
unsigned int F_37 ( struct V_1 * V_2 ,
struct V_33 * V_33 , T_4 * V_48 )
{
unsigned int V_83 = 0 ;
F_38 ( V_33 , & V_2 -> V_15 . V_48 , V_48 ) ;
F_18 ( & V_2 -> V_47 ) ;
if ( ! F_39 ( & V_2 -> V_15 ) ) {
V_83 = V_84 ;
} else if ( V_2 -> V_8 == V_85 &&
V_2 -> V_64 == V_33 ) {
V_83 |= ( V_86 | V_87 ) ;
F_6 ( & V_2 -> V_20 -> V_2 , L_24 ) ;
F_35 ( V_2 ) ;
}
F_16 ( & V_2 -> V_47 ) ;
return V_83 ;
}
int F_40 ( struct V_13 * V_14 , struct V_32 * V_34 ,
struct V_32 * V_88 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_60 V_61 ;
T_2 V_89 = V_2 -> V_4 - V_2 -> V_5 ;
T_5 V_90 = F_41 ( V_89 ) ;
int V_91 ;
int V_39 ;
V_39 = F_26 ( V_14 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_39 == 0 ) {
F_42 ( V_2 , V_14 , L_25 ) ;
return 0 ;
}
V_61 . V_67 = V_14 -> V_68 ;
V_61 . V_69 = V_14 -> V_22 ;
V_61 . V_70 = 0 ;
V_61 . V_71 = 0 ;
V_91 = F_43 ( V_2 ) ;
if ( V_91 >= V_90 ) {
V_61 . V_37 = V_89 ;
V_61 . V_66 = 1 ;
} else if ( V_91 == V_2 -> V_92 ) {
V_90 = V_91 ;
V_89 = ( V_91 * sizeof( T_5 ) ) - sizeof( struct V_60 ) ;
V_61 . V_37 = V_89 ;
V_61 . V_66 = 0 ;
} else {
return 0 ;
}
F_6 ( & V_2 -> V_20 -> V_2 , V_93 , F_44 ( & V_61 ) ) ;
V_39 = F_29 ( V_2 , & V_61 ,
V_2 -> V_28 + V_2 -> V_5 ) ;
if ( V_39 ) {
V_2 -> V_8 = V_9 ;
V_14 -> V_82 = V_39 ;
F_21 ( & V_34 -> V_53 ) ;
return V_39 ;
}
if ( F_30 ( V_14 ) )
return - V_72 ;
V_2 -> V_5 += V_61 . V_37 ;
V_14 -> V_82 = 0 ;
if ( V_61 . V_66 ) {
V_2 -> V_8 = V_74 ;
V_2 -> V_73 = true ;
V_34 -> V_54 = V_2 -> V_5 ;
V_2 -> V_3 = V_34 ;
F_45 ( & V_34 -> V_53 , & V_2 -> V_75 . V_53 ) ;
}
return 0 ;
}
int F_46 ( struct V_1 * V_2 ,
struct V_60 * V_61 ,
struct V_32 * V_94 )
{
struct V_32 * V_34 ;
unsigned char * V_95 ;
F_47 ( V_61 -> V_69 != V_2 -> V_15 . V_22 ) ;
F_47 ( V_2 -> V_8 != V_96 ) ;
V_95 = V_2 -> V_28 + V_2 -> V_5 ;
F_47 ( V_2 -> V_25 < V_2 -> V_5 + V_61 -> V_37 ) ;
F_48 ( V_2 , V_95 , V_61 -> V_37 ) ;
V_2 -> V_5 += V_61 -> V_37 ;
if ( ! V_61 -> V_66 )
return 0 ;
F_6 ( & V_2 -> V_20 -> V_2 , L_26 ,
V_61 -> V_37 ) ;
F_6 ( & V_2 -> V_20 -> V_2 , L_27 ) ;
if ( ! V_2 -> V_3 )
return - V_62 ;
V_34 = V_2 -> V_3 ;
V_2 -> V_3 = NULL ;
if ( ! V_34 -> V_14 )
return - V_62 ;
V_2 -> V_11 = 0 ;
V_34 -> V_54 = V_2 -> V_5 ;
V_34 -> V_50 = V_52 ;
if ( V_2 -> V_7 && V_34 -> V_14 == & V_2 -> V_15 ) {
F_6 ( & V_2 -> V_20 -> V_2 , L_28 ) ;
F_6 ( & V_2 -> V_20 -> V_2 , L_29 ) ;
F_31 ( & V_34 -> V_53 , & V_94 -> V_53 ) ;
}
return 0 ;
}
int F_49 ( struct V_1 * V_2 , T_6 * V_91 )
{
T_5 V_90 = F_41 ( sizeof( struct V_97 ) ) ;
if ( * V_91 < V_90 )
return - V_98 ;
* V_91 -= V_90 ;
if ( F_50 ( V_2 , & V_2 -> V_15 ) ) {
F_6 ( & V_2 -> V_20 -> V_2 , L_30 ) ;
return - V_72 ;
}
F_6 ( & V_2 -> V_20 -> V_2 , L_31 ) ;
V_2 -> V_8 = V_96 ;
V_2 -> V_73 = false ;
V_2 -> V_5 = 0 ;
V_2 -> V_4 = 0 ;
V_2 -> V_11 = V_99 ;
V_2 -> V_100 = F_51 ( V_2 ) ;
return 0 ;
}
void F_52 ( struct V_1 * V_2 , struct V_32 * V_34 )
{
if ( V_2 -> V_6 != 1 ) {
V_2 -> V_8 = V_85 ;
V_2 -> V_11 = 0 ;
memcpy ( V_34 -> V_55 . V_57 ,
V_2 -> V_28 ,
V_2 -> V_5 ) ;
F_31 ( & V_34 -> V_53 , & V_2 -> V_101 . V_53 ) ;
F_6 ( & V_2 -> V_20 -> V_2 , L_32 ) ;
V_2 -> V_10 = V_52 ;
F_6 ( & V_2 -> V_20 -> V_2 , L_33 ,
V_2 -> V_10 ) ;
} else {
F_35 ( V_2 ) ;
}
F_6 ( & V_2 -> V_20 -> V_2 , L_34 ) ;
F_53 ( & V_2 -> V_15 . V_48 ) ;
}
static bool F_54 ( struct V_1 * V_2 ,
const struct V_33 * V_33 , struct V_102 * V_103 )
{
struct V_32 * V_104 = NULL ;
struct V_32 * V_105 = NULL ;
bool V_106 = false ;
F_36 (cb_pos, cb_next, mei_cb_list, list) {
if ( V_33 == V_104 -> V_35 ) {
F_21 ( & V_104 -> V_53 ) ;
if ( V_2 -> V_3 == V_104 ) {
V_2 -> V_3 = NULL ;
F_50 ( V_2 ,
& V_2 -> V_15 ) ;
}
F_24 ( V_104 ) ;
V_104 = NULL ;
V_106 = true ;
}
}
return V_106 ;
}
static bool F_55 ( struct V_1 * V_2 , struct V_33 * V_33 )
{
bool V_106 = false ;
F_54 ( V_2 , V_33 , & V_2 -> V_79 . V_53 ) ;
if ( F_54 ( V_2 , V_33 , & V_2 -> V_101 . V_53 ) )
V_106 = true ;
F_54 ( V_2 , V_33 , & V_2 -> V_107 . V_53 ) ;
if ( F_54 ( V_2 , V_33 , & V_2 -> V_108 . V_53 ) )
V_106 = true ;
if ( F_54 ( V_2 , V_33 , & V_2 -> V_75 . V_53 ) )
V_106 = true ;
if ( F_54 ( V_2 , V_33 , & V_2 -> V_76 . V_53 ) )
V_106 = true ;
if ( V_2 -> V_3 && ! V_106 ) {
if ( V_2 -> V_3 -> V_35 == V_33 ) {
F_24 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
V_106 = true ;
}
}
return V_106 ;
}
int F_56 ( struct V_1 * V_2 , struct V_33 * V_33 )
{
if ( V_2 -> V_12 > 0 )
V_2 -> V_12 -- ;
if ( V_2 -> V_64 == V_33 &&
V_2 -> V_8 != V_9 ) {
F_6 ( & V_2 -> V_20 -> V_2 , L_35 ,
V_2 -> V_8 ) ;
V_2 -> V_6 = true ;
if ( V_2 -> V_8 == V_85 ) {
F_6 ( & V_2 -> V_20 -> V_2 , L_36 ) ;
F_35 ( V_2 ) ;
}
}
if ( F_55 ( V_2 , V_33 ) )
V_2 -> V_8 = V_9 ;
return 0 ;
}
