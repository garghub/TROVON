static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned V_5 ;
unsigned long V_6 ;
unsigned int V_7 ;
bool V_8 = false ;
int V_9 = V_4 -> V_9 ;
struct V_10 * V_11 = V_4 -> V_12 ;
struct V_13 * V_14 ;
struct V_15 * V_16 = V_11 -> V_17 ;
struct V_18 * V_19 = V_16 -> V_19 ;
if ( ! V_16 -> V_20 || V_4 -> V_9 == - V_21 )
return;
if ( V_9 )
F_2 ( L_1 ,
V_22 , V_9 , V_4 -> V_23 , V_4 -> V_24 ) ;
V_14 = V_16 -> V_25 ;
if ( ! V_14 )
goto exit;
F_3 ( & V_16 -> V_26 , V_6 ) ;
if ( V_14 -> V_27 == V_28 ) {
V_4 -> V_24 = V_19 -> V_29 ;
V_19 -> V_30 += V_19 -> V_31 ;
if ( V_19 -> V_30 / V_19 -> V_32 >= V_19 -> V_33 ) {
V_4 -> V_24 += V_19 -> V_33 ;
V_19 -> V_30 -= V_19 -> V_33 *
V_19 -> V_32 ;
}
V_4 -> V_23 = V_4 -> V_24 ;
}
V_5 = V_16 -> V_7 % V_16 -> V_34 ;
V_5 += V_4 -> V_23 ;
if ( V_5 >= V_16 -> V_34 )
V_8 = true ;
V_7 = V_16 -> V_7 ;
V_16 -> V_7 = ( V_16 -> V_7 + V_4 -> V_23 ) % V_16 -> V_35 ;
F_4 ( & V_16 -> V_26 , V_6 ) ;
V_5 = V_16 -> V_35 - V_7 ;
if ( V_14 -> V_27 == V_28 ) {
if ( F_5 ( V_5 < V_4 -> V_23 ) ) {
memcpy ( V_4 -> V_36 , V_16 -> V_37 + V_7 , V_5 ) ;
memcpy ( V_4 -> V_36 + V_5 , V_16 -> V_37 ,
V_4 -> V_23 - V_5 ) ;
} else {
memcpy ( V_4 -> V_36 , V_16 -> V_37 + V_7 , V_4 -> V_23 ) ;
}
} else {
if ( F_5 ( V_5 < V_4 -> V_23 ) ) {
memcpy ( V_16 -> V_37 + V_7 , V_4 -> V_36 , V_5 ) ;
memcpy ( V_16 -> V_37 , V_4 -> V_36 + V_5 ,
V_4 -> V_23 - V_5 ) ;
} else {
memcpy ( V_16 -> V_37 + V_7 , V_4 -> V_36 , V_4 -> V_23 ) ;
}
}
exit:
if ( F_6 ( V_2 , V_4 , V_38 ) )
F_7 ( V_19 -> V_39 -> V_40 , L_2 , __LINE__ ) ;
if ( V_8 )
F_8 ( V_14 ) ;
}
static int F_9 ( struct V_13 * V_14 , int V_41 )
{
struct V_18 * V_19 = F_10 ( V_14 ) ;
struct V_15 * V_16 ;
struct V_42 * V_43 ;
struct V_44 * V_45 ;
unsigned long V_6 ;
int V_46 = 0 ;
V_43 = V_19 -> V_43 ;
V_45 = & V_43 -> V_45 ;
if ( V_14 -> V_27 == V_28 )
V_16 = & V_19 -> V_47 ;
else
V_16 = & V_19 -> V_48 ;
F_3 ( & V_16 -> V_26 , V_6 ) ;
V_16 -> V_7 = 0 ;
switch ( V_41 ) {
case V_49 :
case V_50 :
V_16 -> V_25 = V_14 ;
break;
case V_51 :
case V_52 :
V_16 -> V_25 = NULL ;
break;
default:
V_46 = - V_53 ;
}
F_4 ( & V_16 -> V_26 , V_6 ) ;
if ( V_14 -> V_27 == V_28 && ! V_16 -> V_25 )
memset ( V_16 -> V_54 , 0 , V_16 -> V_55 * V_45 -> V_56 ) ;
return V_46 ;
}
static T_1 F_11 ( struct V_13 * V_14 )
{
struct V_18 * V_19 = F_10 ( V_14 ) ;
struct V_15 * V_16 ;
if ( V_14 -> V_27 == V_28 )
V_16 = & V_19 -> V_47 ;
else
V_16 = & V_19 -> V_48 ;
return F_12 ( V_14 -> V_57 , V_16 -> V_7 ) ;
}
static int F_13 ( struct V_13 * V_14 ,
struct V_58 * V_59 )
{
struct V_18 * V_19 = F_10 ( V_14 ) ;
struct V_15 * V_16 ;
int V_46 ;
if ( V_14 -> V_27 == V_28 )
V_16 = & V_19 -> V_47 ;
else
V_16 = & V_19 -> V_48 ;
V_46 = F_14 ( V_14 ,
F_15 ( V_59 ) ) ;
if ( V_46 >= 0 ) {
V_16 -> V_35 = V_14 -> V_57 -> V_35 ;
V_16 -> V_37 = V_14 -> V_57 -> V_37 ;
V_16 -> V_34 = F_16 ( V_59 ) ;
}
return V_46 ;
}
static int F_17 ( struct V_13 * V_14 )
{
struct V_18 * V_19 = F_10 ( V_14 ) ;
struct V_15 * V_16 ;
if ( V_14 -> V_27 == V_28 )
V_16 = & V_19 -> V_47 ;
else
V_16 = & V_19 -> V_48 ;
V_16 -> V_37 = NULL ;
V_16 -> V_35 = 0 ;
V_16 -> V_34 = 0 ;
return F_18 ( V_14 ) ;
}
static int F_19 ( struct V_13 * V_14 )
{
struct V_18 * V_19 = F_10 ( V_14 ) ;
struct V_60 * V_57 = V_14 -> V_57 ;
struct V_42 * V_43 ;
struct V_44 * V_45 ;
int V_61 , V_62 ;
int V_63 , V_64 ;
int V_65 , V_66 ;
V_43 = V_19 -> V_43 ;
V_45 = & V_43 -> V_45 ;
V_61 = V_45 -> V_61 ;
V_62 = V_45 -> V_62 ;
V_63 = V_45 -> V_63 ;
V_64 = V_45 -> V_64 ;
V_65 = V_45 -> V_65 ;
V_66 = V_45 -> V_66 ;
V_19 -> V_30 = 0 ;
V_57 -> V_67 = V_68 ;
if ( V_14 -> V_27 == V_28 ) {
F_20 ( & V_19 -> V_47 . V_26 ) ;
V_57 -> V_67 . V_69 = V_63 ;
switch ( V_61 ) {
case 3 :
V_57 -> V_67 . V_70 = V_71 ;
break;
case 4 :
V_57 -> V_67 . V_70 = V_72 ;
break;
default:
V_57 -> V_67 . V_70 = V_73 ;
break;
}
V_57 -> V_67 . V_74 = F_21 ( V_65 ) ;
V_57 -> V_67 . V_75 = 2 * V_19 -> V_47 . V_55
/ V_57 -> V_67 . V_76 ;
} else {
F_20 ( & V_19 -> V_48 . V_26 ) ;
V_57 -> V_67 . V_69 = V_64 ;
switch ( V_62 ) {
case 3 :
V_57 -> V_67 . V_70 = V_71 ;
break;
case 4 :
V_57 -> V_67 . V_70 = V_72 ;
break;
default:
V_57 -> V_67 . V_70 = V_73 ;
break;
}
V_57 -> V_67 . V_74 = F_21 ( V_66 ) ;
V_57 -> V_67 . V_75 = 2 * V_19 -> V_48 . V_55
/ V_57 -> V_67 . V_76 ;
}
V_57 -> V_67 . V_77 = V_57 -> V_67 . V_69 ;
V_57 -> V_67 . V_78 = V_57 -> V_67 . V_74 ;
F_22 ( V_57 , V_79 ) ;
return 0 ;
}
static int F_23 ( struct V_13 * V_14 )
{
return 0 ;
}
static inline void F_24 ( struct V_15 * V_16 , struct V_1 * V_2 )
{
struct V_18 * V_19 = V_16 -> V_19 ;
struct V_42 * V_43 ;
struct V_44 * V_45 ;
int V_80 ;
if ( ! V_16 -> V_20 )
return;
V_16 -> V_20 = false ;
V_43 = V_19 -> V_43 ;
V_45 = & V_43 -> V_45 ;
for ( V_80 = 0 ; V_80 < V_45 -> V_56 ; V_80 ++ ) {
if ( V_16 -> V_81 [ V_80 ] . V_4 ) {
F_25 ( V_2 , V_16 -> V_81 [ V_80 ] . V_4 ) ;
F_26 ( V_2 , V_16 -> V_81 [ V_80 ] . V_4 ) ;
V_16 -> V_81 [ V_80 ] . V_4 = NULL ;
}
}
if ( F_27 ( V_2 ) )
F_7 ( V_19 -> V_39 -> V_40 , L_3 , V_22 , __LINE__ ) ;
}
int F_28 ( struct V_42 * V_43 )
{
struct V_18 * V_19 = V_43 -> V_19 ;
struct V_82 * V_83 = V_43 -> V_83 ;
struct V_84 * V_40 = & V_83 -> V_40 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_15 * V_16 ;
struct V_44 * V_45 = & V_43 -> V_45 ;
int V_85 , V_80 ;
V_2 = V_43 -> V_86 ;
V_16 = & V_19 -> V_48 ;
F_29 ( V_83 , & V_43 -> V_87 , V_2 ) ;
V_85 = V_16 -> V_55 ;
V_16 -> V_20 = true ;
F_30 ( V_2 ) ;
for ( V_80 = 0 ; V_80 < V_45 -> V_56 ; V_80 ++ ) {
if ( ! V_16 -> V_81 [ V_80 ] . V_4 ) {
V_4 = F_31 ( V_2 , V_38 ) ;
if ( V_4 == NULL )
return - V_88 ;
V_16 -> V_81 [ V_80 ] . V_4 = V_4 ;
V_16 -> V_81 [ V_80 ] . V_17 = V_16 ;
V_4 -> V_89 = 0 ;
V_4 -> V_12 = & V_16 -> V_81 [ V_80 ] ;
V_4 -> V_24 = V_85 ;
V_4 -> V_90 = F_1 ;
V_4 -> V_36 = V_16 -> V_54 + V_80 * V_16 -> V_55 ;
}
if ( F_6 ( V_2 , V_16 -> V_81 [ V_80 ] . V_4 , V_38 ) )
F_7 ( V_40 , L_3 , V_22 , __LINE__ ) ;
}
return 0 ;
}
void F_32 ( struct V_42 * V_43 )
{
struct V_18 * V_19 = V_43 -> V_19 ;
F_24 ( & V_19 -> V_48 , V_43 -> V_86 ) ;
}
int F_33 ( struct V_42 * V_43 )
{
struct V_18 * V_19 = V_43 -> V_19 ;
struct V_82 * V_83 = V_43 -> V_83 ;
struct V_84 * V_40 = & V_83 -> V_40 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_15 * V_16 ;
struct V_44 * V_45 = & V_43 -> V_45 ;
unsigned int V_91 , V_92 ;
const struct V_93 * V_94 ;
int V_85 , V_80 ;
V_2 = V_43 -> V_95 ;
V_16 = & V_19 -> V_47 ;
F_29 ( V_83 , & V_43 -> V_87 , V_2 ) ;
V_94 = V_2 -> V_96 ;
if ( V_83 -> V_97 == V_98 )
V_91 = 1000 ;
else
V_91 = 8000 ;
V_19 -> V_33 = V_45 -> V_61 *
F_21 ( V_45 -> V_65 ) ;
V_92 = V_45 -> V_63 * V_19 -> V_33 ;
V_19 -> V_32 = V_91 / ( 1 << ( V_94 -> V_99 - 1 ) ) ;
V_19 -> V_29 = F_34 (unsigned int, rate / uac->p_interval,
prm->max_psize) ;
if ( V_19 -> V_29 < V_16 -> V_55 )
V_19 -> V_31 = V_92 % V_19 -> V_32 ;
else
V_19 -> V_31 = 0 ;
V_85 = V_19 -> V_29 ;
V_19 -> V_30 = 0 ;
V_16 -> V_20 = true ;
F_30 ( V_2 ) ;
for ( V_80 = 0 ; V_80 < V_45 -> V_56 ; V_80 ++ ) {
if ( ! V_16 -> V_81 [ V_80 ] . V_4 ) {
V_4 = F_31 ( V_2 , V_38 ) ;
if ( V_4 == NULL )
return - V_88 ;
V_16 -> V_81 [ V_80 ] . V_4 = V_4 ;
V_16 -> V_81 [ V_80 ] . V_17 = V_16 ;
V_4 -> V_89 = 0 ;
V_4 -> V_12 = & V_16 -> V_81 [ V_80 ] ;
V_4 -> V_24 = V_85 ;
V_4 -> V_90 = F_1 ;
V_4 -> V_36 = V_16 -> V_54 + V_80 * V_16 -> V_55 ;
}
if ( F_6 ( V_2 , V_16 -> V_81 [ V_80 ] . V_4 , V_38 ) )
F_7 ( V_40 , L_3 , V_22 , __LINE__ ) ;
}
return 0 ;
}
void F_35 ( struct V_42 * V_43 )
{
struct V_18 * V_19 = V_43 -> V_19 ;
F_24 ( & V_19 -> V_47 , V_43 -> V_95 ) ;
}
int F_36 ( struct V_42 * V_42 , const char * V_100 ,
const char * V_101 )
{
struct V_18 * V_19 ;
struct V_102 * V_39 ;
struct V_103 * V_104 ;
struct V_44 * V_45 ;
int V_65 , V_66 ;
int V_46 ;
if ( ! V_42 )
return - V_53 ;
V_19 = F_37 ( sizeof( * V_19 ) , V_105 ) ;
if ( ! V_19 )
return - V_88 ;
V_42 -> V_19 = V_19 ;
V_19 -> V_43 = V_42 ;
V_45 = & V_42 -> V_45 ;
V_65 = V_45 -> V_65 ;
V_66 = V_45 -> V_66 ;
if ( V_66 ) {
struct V_15 * V_16 = & V_19 -> V_48 ;
V_19 -> V_48 . V_19 = V_19 ;
V_16 -> V_55 = V_42 -> V_106 ;
V_16 -> V_81 = F_38 ( V_45 -> V_56 , sizeof( struct V_10 ) ,
V_105 ) ;
if ( ! V_16 -> V_81 ) {
V_46 = - V_88 ;
goto V_107;
}
V_16 -> V_54 = F_38 ( V_45 -> V_56 , V_16 -> V_55 ,
V_105 ) ;
if ( ! V_16 -> V_54 ) {
V_16 -> V_55 = 0 ;
V_46 = - V_88 ;
goto V_107;
}
}
if ( V_65 ) {
struct V_15 * V_16 = & V_19 -> V_47 ;
V_19 -> V_47 . V_19 = V_19 ;
V_16 -> V_55 = V_42 -> V_108 ;
V_16 -> V_81 = F_38 ( V_45 -> V_56 , sizeof( struct V_10 ) ,
V_105 ) ;
if ( ! V_16 -> V_81 ) {
V_46 = - V_88 ;
goto V_107;
}
V_16 -> V_54 = F_38 ( V_45 -> V_56 , V_16 -> V_55 ,
V_105 ) ;
if ( ! V_16 -> V_54 ) {
V_16 -> V_55 = 0 ;
V_46 = - V_88 ;
goto V_107;
}
}
V_46 = F_39 ( & V_42 -> V_83 -> V_40 ,
- 1 , NULL , V_109 , 0 , & V_39 ) ;
if ( V_46 < 0 )
goto V_107;
V_19 -> V_39 = V_39 ;
V_46 = F_40 ( V_19 -> V_39 , V_100 , 0 ,
V_65 ? 1 : 0 , V_66 ? 1 : 0 , & V_104 ) ;
if ( V_46 < 0 )
goto V_110;
strcpy ( V_104 -> V_111 , V_100 ) ;
V_104 -> V_112 = V_19 ;
V_19 -> V_104 = V_104 ;
F_41 ( V_104 , V_28 , & V_113 ) ;
F_41 ( V_104 , V_114 , & V_113 ) ;
strcpy ( V_39 -> V_115 , V_101 ) ;
strcpy ( V_39 -> V_116 , V_101 ) ;
sprintf ( V_39 -> V_117 , L_4 , V_101 , V_39 -> V_40 -> V_118 ) ;
F_42 ( V_104 , V_119 ,
F_43 ( V_105 ) , 0 , V_120 ) ;
V_46 = F_44 ( V_39 ) ;
if ( ! V_46 )
return 0 ;
V_110:
F_45 ( V_39 ) ;
V_107:
F_46 ( V_19 -> V_47 . V_81 ) ;
F_46 ( V_19 -> V_48 . V_81 ) ;
F_46 ( V_19 -> V_47 . V_54 ) ;
F_46 ( V_19 -> V_48 . V_54 ) ;
F_46 ( V_19 ) ;
return V_46 ;
}
void F_47 ( struct V_42 * V_42 )
{
struct V_18 * V_19 ;
struct V_102 * V_39 ;
if ( ! V_42 || ! V_42 -> V_19 )
return;
V_19 = V_42 -> V_19 ;
V_39 = V_19 -> V_39 ;
if ( V_39 )
F_45 ( V_39 ) ;
F_46 ( V_19 -> V_47 . V_81 ) ;
F_46 ( V_19 -> V_48 . V_81 ) ;
F_46 ( V_19 -> V_47 . V_54 ) ;
F_46 ( V_19 -> V_48 . V_54 ) ;
F_46 ( V_19 ) ;
}
