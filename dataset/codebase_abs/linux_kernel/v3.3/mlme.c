void F_1 ( struct V_1 * V_2 , const T_1 * V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_11 * V_12 = (struct V_11 * ) V_3 ;
T_1 * V_13 = V_12 -> V_13 ;
int V_14 ;
T_3 V_15 = F_3 ( V_12 -> V_16 . V_17 . V_18 ) ;
bool V_19 = false ;
F_4 ( V_6 ) ;
for ( V_14 = 0 ; V_14 < V_20 ; V_14 ++ ) {
if ( V_6 -> V_21 [ V_14 ] &&
memcmp ( V_6 -> V_21 [ V_14 ] -> V_22 . V_13 , V_13 ,
V_23 ) == 0 ) {
if ( V_15 == V_24 ) {
V_6 -> V_25 [ V_14 ] = V_6 -> V_21 [ V_14 ] ;
} else {
F_5 ( V_6 -> V_21 [ V_14 ] ) ;
F_6 ( & V_6 -> V_21 [ V_14 ] -> V_22 ) ;
}
V_6 -> V_21 [ V_14 ] = NULL ;
V_19 = true ;
break;
}
}
if ( V_19 ) {
F_7 ( V_10 , V_2 , V_3 , V_4 , V_26 ) ;
F_8 ( V_2 , V_3 , V_4 ) ;
}
F_9 ( V_6 ) ;
}
void F_10 ( struct V_1 * V_2 , const T_1 * V_3 , T_2 V_4 )
{
T_3 V_18 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_11 * V_12 = (struct V_11 * ) V_3 ;
T_1 * V_27 = V_12 -> V_16 . V_28 . V_29 ;
int V_14 , V_30 = F_11 ( struct V_11 , V_16 . V_28 . V_29 ) ;
struct V_31 * V_32 = NULL ;
F_4 ( V_6 ) ;
V_18 = F_3 ( V_12 -> V_16 . V_28 . V_18 ) ;
if ( V_18 != V_24 && V_6 -> V_33 &&
F_12 ( V_6 ) )
goto V_34;
F_13 ( V_10 , V_2 , V_3 , V_4 , V_26 ) ;
if ( V_18 == V_24 ) {
for ( V_14 = 0 ; V_14 < V_20 ; V_14 ++ ) {
if ( ! V_6 -> V_25 [ V_14 ] )
continue;
if ( memcmp ( V_6 -> V_25 [ V_14 ] -> V_22 . V_13 , V_12 -> V_13 ,
V_23 ) == 0 ) {
V_32 = V_6 -> V_25 [ V_14 ] ;
V_6 -> V_25 [ V_14 ] = NULL ;
F_14 ( V_32 ) ;
break;
}
}
if ( ! V_32 )
goto V_34;
} else if ( V_6 -> V_33 ) {
F_15 ( V_6 ) ;
goto V_34;
}
if ( ! V_6 -> V_33 && V_6 -> V_35 == V_36 ) {
V_6 -> V_35 = V_37 ;
}
F_16 ( V_2 , V_12 -> V_13 , NULL , 0 , V_27 , V_4 - V_30 ,
V_18 ,
V_18 == V_24 ,
V_32 ? & V_32 -> V_22 : NULL ) ;
if ( V_32 ) {
F_5 ( V_32 ) ;
F_6 ( & V_32 -> V_22 ) ;
}
V_34:
F_9 ( V_6 ) ;
}
void F_17 ( struct V_1 * V_2 ,
const T_1 * V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_11 * V_12 = (struct V_11 * ) V_3 ;
const T_1 * V_13 = V_12 -> V_13 ;
int V_14 ;
bool V_38 = false , V_39 = false ;
F_18 ( V_6 ) ;
if ( V_6 -> V_40 &&
memcmp ( V_6 -> V_40 -> V_22 . V_13 , V_13 , V_23 ) == 0 ) {
F_5 ( V_6 -> V_40 ) ;
F_6 ( & V_6 -> V_40 -> V_22 ) ;
V_6 -> V_40 = NULL ;
V_38 = true ;
V_39 = true ;
} else for ( V_14 = 0 ; V_14 < V_20 ; V_14 ++ ) {
if ( V_6 -> V_25 [ V_14 ] &&
memcmp ( V_6 -> V_25 [ V_14 ] -> V_22 . V_13 , V_13 , V_23 ) == 0 ) {
F_5 ( V_6 -> V_25 [ V_14 ] ) ;
F_6 ( & V_6 -> V_25 [ V_14 ] -> V_22 ) ;
V_6 -> V_25 [ V_14 ] = NULL ;
V_38 = true ;
break;
}
if ( V_6 -> V_21 [ V_14 ] &&
memcmp ( V_6 -> V_21 [ V_14 ] -> V_22 . V_13 , V_13 ,
V_23 ) == 0 &&
memcmp ( V_12 -> V_41 , V_2 -> V_42 , V_23 ) == 0 ) {
F_5 ( V_6 -> V_21 [ V_14 ] ) ;
F_6 ( & V_6 -> V_21 [ V_14 ] -> V_22 ) ;
V_6 -> V_21 [ V_14 ] = NULL ;
V_38 = true ;
break;
}
}
if ( ! V_38 )
return;
F_19 ( V_10 , V_2 , V_3 , V_4 , V_26 ) ;
if ( V_6 -> V_35 == V_43 && V_39 ) {
T_3 V_44 ;
bool V_45 ;
V_44 = F_3 ( V_12 -> V_16 . V_46 . V_44 ) ;
V_45 = memcmp ( V_12 -> V_41 , V_2 -> V_42 , V_23 ) != 0 ;
F_20 ( V_2 , NULL , 0 , V_44 , V_45 ) ;
} else if ( V_6 -> V_35 == V_37 ) {
F_16 ( V_2 , V_12 -> V_13 , NULL , 0 , NULL , 0 ,
V_47 ,
false , NULL ) ;
}
}
void F_21 ( struct V_1 * V_2 , const T_1 * V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_4 ( V_6 ) ;
F_17 ( V_2 , V_3 , V_4 ) ;
F_9 ( V_6 ) ;
}
void F_22 ( struct V_1 * V_2 ,
const T_1 * V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_11 * V_12 = (struct V_11 * ) V_3 ;
const T_1 * V_13 = V_12 -> V_13 ;
int V_14 ;
T_3 V_44 ;
bool V_45 ;
bool V_19 = false ;
F_18 ( V_6 ) ;
F_23 ( V_10 , V_2 , V_3 , V_4 , V_26 ) ;
if ( V_6 -> V_35 != V_43 )
return;
if ( V_6 -> V_40 &&
memcmp ( V_6 -> V_40 -> V_22 . V_13 , V_13 , V_23 ) == 0 ) {
for ( V_14 = 0 ; V_14 < V_20 ; V_14 ++ ) {
if ( V_6 -> V_21 [ V_14 ] || V_6 -> V_25 [ V_14 ] )
continue;
V_6 -> V_25 [ V_14 ] = V_6 -> V_40 ;
V_6 -> V_40 = NULL ;
V_19 = true ;
F_24 ( V_2 , V_14 ) ;
break;
}
F_25 ( ! V_19 ) ;
} else
F_25 ( 1 ) ;
V_44 = F_3 ( V_12 -> V_16 . V_48 . V_44 ) ;
V_45 = memcmp ( V_12 -> V_41 , V_2 -> V_42 , V_23 ) != 0 ;
F_20 ( V_2 , NULL , 0 , V_44 , V_45 ) ;
}
void F_26 ( struct V_1 * V_2 , const T_1 * V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_4 ( V_6 ) ;
F_22 ( V_2 , V_3 , V_4 ) ;
F_9 ( V_6 ) ;
}
void F_27 ( struct V_1 * V_2 , const T_1 * V_3 ,
T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_28 ( V_10 , V_2 , V_3 , V_4 , V_49 ) ;
}
void F_29 ( struct V_1 * V_2 , const T_1 * V_3 ,
T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_30 ( V_10 , V_2 , V_3 , V_4 , V_49 ) ;
}
static void F_31 ( struct V_5 * V_6 , const T_1 * V_50 )
{
int V_14 ;
bool V_19 = false ;
F_18 ( V_6 ) ;
for ( V_14 = 0 ; V_50 && V_14 < V_20 ; V_14 ++ ) {
if ( V_6 -> V_21 [ V_14 ] &&
memcmp ( V_6 -> V_21 [ V_14 ] -> V_22 . V_13 ,
V_50 , V_23 ) == 0 ) {
F_5 ( V_6 -> V_21 [ V_14 ] ) ;
F_6 ( & V_6 -> V_21 [ V_14 ] -> V_22 ) ;
V_6 -> V_21 [ V_14 ] = NULL ;
V_19 = true ;
break;
}
}
F_25 ( ! V_19 ) ;
}
void F_32 ( struct V_1 * V_2 , const T_1 * V_50 )
{
F_31 ( V_2 -> V_7 , V_50 ) ;
}
void F_33 ( struct V_1 * V_2 , const T_1 * V_50 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_4 ( V_6 ) ;
F_34 ( V_10 , V_2 , V_50 , V_26 ) ;
if ( V_6 -> V_35 == V_37 )
F_16 ( V_2 , V_50 , NULL , 0 , NULL , 0 ,
V_47 ,
false , NULL ) ;
F_31 ( V_6 , V_50 ) ;
F_9 ( V_6 ) ;
}
void F_35 ( struct V_1 * V_2 , const T_1 * V_50 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
int V_14 ;
bool V_19 = false ;
F_4 ( V_6 ) ;
F_36 ( V_10 , V_2 , V_50 , V_26 ) ;
if ( V_6 -> V_35 == V_37 )
F_16 ( V_2 , V_50 , NULL , 0 , NULL , 0 ,
V_47 ,
false , NULL ) ;
for ( V_14 = 0 ; V_50 && V_14 < V_20 ; V_14 ++ ) {
if ( V_6 -> V_25 [ V_14 ] &&
memcmp ( V_6 -> V_25 [ V_14 ] -> V_22 . V_13 ,
V_50 , V_23 ) == 0 ) {
F_5 ( V_6 -> V_25 [ V_14 ] ) ;
F_6 ( & V_6 -> V_25 [ V_14 ] -> V_22 ) ;
V_6 -> V_25 [ V_14 ] = NULL ;
V_19 = true ;
break;
}
}
F_25 ( ! V_19 ) ;
F_9 ( V_6 ) ;
}
void F_37 ( struct V_1 * V_2 , const T_1 * V_50 ,
enum V_51 V_52 , int V_53 ,
const T_1 * V_54 , T_4 V_55 )
{
struct V_8 * V_8 = V_2 -> V_7 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
#ifdef F_38
union V_56 V_57 ;
char * V_3 = F_39 ( 128 , V_55 ) ;
if ( V_3 ) {
sprintf ( V_3 , L_1
L_2 , V_53 ,
V_52 == V_58 ? L_3 : L_4 ,
V_50 ) ;
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
V_57 . V_59 . V_60 = strlen ( V_3 ) ;
F_40 ( V_2 , V_61 , & V_57 , V_3 ) ;
F_41 ( V_3 ) ;
}
#endif
F_42 ( V_10 , V_2 , V_50 , V_52 , V_53 , V_54 , V_55 ) ;
}
int F_43 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_62 * V_63 ,
enum V_64 V_65 ,
const T_1 * V_13 ,
const T_1 * V_66 , int V_67 ,
const T_1 * V_27 , int V_68 ,
const T_1 * V_69 , int V_70 , int V_71 ,
bool V_72 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_73 V_74 ;
struct V_31 * V_32 ;
int V_14 , V_75 , V_76 = - 1 , V_77 = 0 ;
F_18 ( V_6 ) ;
if ( V_65 == V_78 )
if ( ! V_69 || ! V_70 || V_71 < 0 || V_71 > 4 )
return - V_79 ;
if ( V_6 -> V_40 &&
memcmp ( V_13 , V_6 -> V_40 -> V_22 . V_13 , V_23 ) == 0 )
return - V_80 ;
for ( V_14 = 0 ; V_14 < V_20 ; V_14 ++ ) {
if ( V_6 -> V_21 [ V_14 ] &&
memcmp ( V_13 , V_6 -> V_21 [ V_14 ] -> V_22 . V_13 ,
V_23 ) == 0 )
return - V_80 ;
if ( V_6 -> V_25 [ V_14 ] &&
memcmp ( V_13 , V_6 -> V_25 [ V_14 ] -> V_22 . V_13 ,
V_23 ) == 0 )
return - V_80 ;
}
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
V_74 . V_72 = V_72 ;
V_74 . V_27 = V_27 ;
V_74 . V_68 = V_68 ;
V_74 . V_65 = V_65 ;
V_74 . V_32 = F_44 ( & V_10 -> V_8 , V_63 , V_13 , V_66 , V_67 ,
V_81 , V_81 ) ;
V_74 . V_69 = V_69 ;
V_74 . V_70 = V_70 ;
V_74 . V_71 = V_71 ;
if ( ! V_74 . V_32 )
return - V_82 ;
V_32 = F_45 ( V_74 . V_32 ) ;
for ( V_14 = 0 ; V_14 < V_20 ; V_14 ++ ) {
if ( ! V_6 -> V_25 [ V_14 ] && ! V_6 -> V_21 [ V_14 ] ) {
V_76 = V_14 ;
V_77 ++ ;
}
}
if ( V_77 < 2 ) {
V_75 = - V_83 ;
goto V_34;
}
if ( V_72 )
V_6 -> V_25 [ V_76 ] = V_32 ;
else
V_6 -> V_21 [ V_76 ] = V_32 ;
F_46 ( V_32 ) ;
V_75 = V_10 -> V_84 -> V_17 ( & V_10 -> V_8 , V_2 , & V_74 ) ;
if ( V_75 ) {
if ( V_72 )
V_6 -> V_25 [ V_76 ] = NULL ;
else
V_6 -> V_21 [ V_76 ] = NULL ;
F_5 ( V_32 ) ;
}
V_34:
if ( V_75 )
F_6 ( V_74 . V_32 ) ;
return V_75 ;
}
int F_47 ( struct V_9 * V_10 ,
struct V_1 * V_2 , struct V_62 * V_63 ,
enum V_64 V_65 , const T_1 * V_13 ,
const T_1 * V_66 , int V_67 ,
const T_1 * V_27 , int V_68 ,
const T_1 * V_69 , int V_70 , int V_71 ,
bool V_72 )
{
int V_75 ;
F_4 ( V_2 -> V_7 ) ;
V_75 = F_43 ( V_10 , V_2 , V_63 , V_65 , V_13 ,
V_66 , V_67 , V_27 , V_68 ,
V_69 , V_70 , V_71 , V_72 ) ;
F_9 ( V_2 -> V_7 ) ;
return V_75 ;
}
void F_48 ( struct V_85 * V_86 ,
const struct V_85 * V_87 )
{
int V_14 ;
T_1 * V_88 , * V_89 ;
if ( ! V_87 ) {
memset ( V_86 , 0 , sizeof( * V_86 ) ) ;
return;
}
V_88 = ( T_1 * ) ( V_86 ) ;
V_89 = ( T_1 * ) ( V_87 ) ;
for ( V_14 = 0 ; V_14 < sizeof( * V_86 ) ; V_14 ++ )
V_88 [ V_14 ] &= V_89 [ V_14 ] ;
}
int F_49 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_62 * V_63 ,
const T_1 * V_13 , const T_1 * V_90 ,
const T_1 * V_66 , int V_67 ,
const T_1 * V_27 , int V_68 , bool V_91 ,
struct V_92 * V_93 ,
T_5 V_94 , struct V_85 * V_86 ,
struct V_85 * V_87 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_95 V_74 ;
struct V_31 * V_32 ;
int V_14 , V_75 , V_76 = - 1 ;
bool V_96 = false ;
F_18 ( V_6 ) ;
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
if ( V_6 -> V_40 && V_90 &&
memcmp ( V_6 -> V_40 -> V_22 . V_13 , V_90 , V_23 ) == 0 ) {
if ( V_6 -> V_35 == V_43 ) {
V_96 = true ;
V_6 -> V_35 = V_37 ;
}
} else if ( V_6 -> V_40 )
return - V_80 ;
V_74 . V_27 = V_27 ;
V_74 . V_68 = V_68 ;
memcpy ( & V_74 . V_97 , V_93 , sizeof( V_74 . V_97 ) ) ;
V_74 . V_91 = V_91 ;
V_74 . V_90 = V_90 ;
V_74 . V_98 = V_94 ;
if ( V_86 )
memcpy ( & V_74 . V_86 , V_86 , sizeof( V_74 . V_86 ) ) ;
if ( V_87 )
memcpy ( & V_74 . V_87 , V_87 ,
sizeof( V_74 . V_87 ) ) ;
F_48 ( & V_74 . V_87 ,
V_10 -> V_8 . V_99 ) ;
V_74 . V_32 = F_44 ( & V_10 -> V_8 , V_63 , V_13 , V_66 , V_67 ,
V_81 , V_81 ) ;
if ( ! V_74 . V_32 ) {
if ( V_96 )
V_6 -> V_35 = V_43 ;
return - V_82 ;
}
V_32 = F_45 ( V_74 . V_32 ) ;
for ( V_14 = 0 ; V_14 < V_20 ; V_14 ++ ) {
if ( V_32 == V_6 -> V_25 [ V_14 ] ) {
V_76 = V_14 ;
break;
}
}
if ( V_76 < 0 ) {
V_75 = - V_100 ;
goto V_34;
}
V_75 = V_10 -> V_84 -> V_101 ( & V_10 -> V_8 , V_2 , & V_74 ) ;
V_34:
if ( V_75 && V_96 )
V_6 -> V_35 = V_43 ;
F_6 ( V_74 . V_32 ) ;
return V_75 ;
}
int F_50 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_62 * V_63 ,
const T_1 * V_13 , const T_1 * V_90 ,
const T_1 * V_66 , int V_67 ,
const T_1 * V_27 , int V_68 , bool V_91 ,
struct V_92 * V_93 ,
T_5 V_94 , struct V_85 * V_86 ,
struct V_85 * V_87 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_75 ;
F_4 ( V_6 ) ;
V_75 = F_49 ( V_10 , V_2 , V_63 , V_13 , V_90 ,
V_66 , V_67 , V_27 , V_68 , V_91 , V_93 ,
V_94 , V_86 , V_87 ) ;
F_9 ( V_6 ) ;
return V_75 ;
}
int F_51 ( struct V_9 * V_10 ,
struct V_1 * V_2 , const T_1 * V_13 ,
const T_1 * V_27 , int V_68 , T_3 V_102 ,
bool V_72 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_103 V_74 ;
int V_14 ;
F_18 ( V_6 ) ;
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
V_74 . V_44 = V_102 ;
V_74 . V_72 = V_72 ;
V_74 . V_27 = V_27 ;
V_74 . V_68 = V_68 ;
if ( V_6 -> V_40 &&
memcmp ( V_6 -> V_40 -> V_22 . V_13 , V_13 , V_23 ) == 0 ) {
V_74 . V_32 = & V_6 -> V_40 -> V_22 ;
} else for ( V_14 = 0 ; V_14 < V_20 ; V_14 ++ ) {
if ( V_6 -> V_25 [ V_14 ] &&
memcmp ( V_13 , V_6 -> V_25 [ V_14 ] -> V_22 . V_13 , V_23 ) == 0 ) {
V_74 . V_32 = & V_6 -> V_25 [ V_14 ] -> V_22 ;
break;
}
if ( V_6 -> V_21 [ V_14 ] &&
memcmp ( V_13 , V_6 -> V_21 [ V_14 ] -> V_22 . V_13 , V_23 ) == 0 ) {
V_74 . V_32 = & V_6 -> V_21 [ V_14 ] -> V_22 ;
break;
}
}
if ( ! V_74 . V_32 )
return - V_100 ;
return V_10 -> V_84 -> V_46 ( & V_10 -> V_8 , V_2 , & V_74 , V_6 ) ;
}
int F_52 ( struct V_9 * V_10 ,
struct V_1 * V_2 , const T_1 * V_13 ,
const T_1 * V_27 , int V_68 , T_3 V_102 ,
bool V_72 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_75 ;
F_4 ( V_6 ) ;
V_75 = F_51 ( V_10 , V_2 , V_13 , V_27 , V_68 , V_102 ,
V_72 ) ;
F_9 ( V_6 ) ;
return V_75 ;
}
static int F_53 ( struct V_9 * V_10 ,
struct V_1 * V_2 , const T_1 * V_13 ,
const T_1 * V_27 , int V_68 , T_3 V_102 ,
bool V_72 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_104 V_74 ;
F_18 ( V_6 ) ;
if ( V_6 -> V_35 != V_43 )
return - V_100 ;
if ( F_25 ( ! V_6 -> V_40 ) )
return - V_100 ;
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
V_74 . V_44 = V_102 ;
V_74 . V_72 = V_72 ;
V_74 . V_27 = V_27 ;
V_74 . V_68 = V_68 ;
if ( memcmp ( V_6 -> V_40 -> V_22 . V_13 , V_13 , V_23 ) == 0 )
V_74 . V_32 = & V_6 -> V_40 -> V_22 ;
else
return - V_100 ;
return V_10 -> V_84 -> V_48 ( & V_10 -> V_8 , V_2 , & V_74 , V_6 ) ;
}
int F_54 ( struct V_9 * V_10 ,
struct V_1 * V_2 , const T_1 * V_13 ,
const T_1 * V_27 , int V_68 , T_3 V_102 ,
bool V_72 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_75 ;
F_4 ( V_6 ) ;
V_75 = F_53 ( V_10 , V_2 , V_13 , V_27 , V_68 , V_102 ,
V_72 ) ;
F_9 ( V_6 ) ;
return V_75 ;
}
void F_55 ( struct V_9 * V_10 ,
struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_103 V_74 ;
int V_14 ;
F_18 ( V_6 ) ;
if ( ! V_10 -> V_84 -> V_46 )
return;
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
V_74 . V_44 = V_105 ;
V_74 . V_27 = NULL ;
V_74 . V_68 = 0 ;
if ( V_6 -> V_40 ) {
V_74 . V_32 = & V_6 -> V_40 -> V_22 ;
V_10 -> V_84 -> V_46 ( & V_10 -> V_8 , V_2 , & V_74 , V_6 ) ;
if ( V_6 -> V_40 ) {
F_5 ( V_6 -> V_40 ) ;
F_6 ( & V_6 -> V_40 -> V_22 ) ;
V_6 -> V_40 = NULL ;
}
}
for ( V_14 = 0 ; V_14 < V_20 ; V_14 ++ ) {
if ( V_6 -> V_25 [ V_14 ] ) {
V_74 . V_32 = & V_6 -> V_25 [ V_14 ] -> V_22 ;
V_10 -> V_84 -> V_46 ( & V_10 -> V_8 , V_2 , & V_74 , V_6 ) ;
if ( V_6 -> V_25 [ V_14 ] ) {
F_5 ( V_6 -> V_25 [ V_14 ] ) ;
F_6 ( & V_6 -> V_25 [ V_14 ] -> V_22 ) ;
V_6 -> V_25 [ V_14 ] = NULL ;
}
}
if ( V_6 -> V_21 [ V_14 ] ) {
V_74 . V_32 = & V_6 -> V_21 [ V_14 ] -> V_22 ;
V_10 -> V_84 -> V_46 ( & V_10 -> V_8 , V_2 , & V_74 , V_6 ) ;
if ( V_6 -> V_21 [ V_14 ] ) {
F_5 ( V_6 -> V_21 [ V_14 ] ) ;
F_6 ( & V_6 -> V_21 [ V_14 ] -> V_22 ) ;
V_6 -> V_21 [ V_14 ] = NULL ;
}
}
}
}
void F_56 ( struct V_1 * V_2 , T_6 V_106 ,
struct V_62 * V_63 ,
enum V_107 V_108 ,
unsigned int V_109 , T_4 V_55 )
{
struct V_8 * V_8 = V_2 -> V_7 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_57 ( V_10 , V_2 , V_106 , V_63 , V_108 ,
V_109 , V_55 ) ;
}
void F_58 ( struct V_1 * V_2 ,
T_6 V_106 ,
struct V_62 * V_63 ,
enum V_107 V_108 ,
T_4 V_55 )
{
struct V_8 * V_8 = V_2 -> V_7 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_59 ( V_10 , V_2 , V_106 , V_63 ,
V_108 , V_55 ) ;
}
void F_60 ( struct V_1 * V_2 , const T_1 * V_110 ,
struct V_111 * V_112 , T_4 V_55 )
{
struct V_8 * V_8 = V_2 -> V_7 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_61 ( V_10 , V_2 , V_110 , V_112 , V_55 ) ;
}
void F_62 ( struct V_1 * V_2 , const T_1 * V_110 , T_4 V_55 )
{
struct V_8 * V_8 = V_2 -> V_7 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_63 ( V_10 , V_2 , V_110 , V_55 ) ;
}
int F_64 ( struct V_5 * V_6 , T_5 V_113 ,
T_3 V_114 , const T_1 * V_115 ,
int V_116 )
{
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_117 * V_118 , * V_119 ;
int V_75 = 0 ;
T_3 V_120 ;
if ( ! V_6 -> V_8 -> V_121 )
return - V_122 ;
if ( ( V_114 & V_123 ) != V_124 )
return - V_79 ;
if ( V_114 & ~ ( V_123 | V_125 ) )
return - V_79 ;
V_120 = ( V_114 & V_125 ) >> 4 ;
if ( ! ( V_6 -> V_8 -> V_121 [ V_6 -> V_126 ] . V_127 & F_65 ( V_120 ) ) )
return - V_79 ;
V_119 = F_66 ( sizeof( * V_118 ) + V_116 , V_26 ) ;
if ( ! V_119 )
return - V_128 ;
F_67 ( & V_6 -> V_129 ) ;
F_68 (reg, &wdev->mgmt_registrations, list) {
int V_130 = F_69 ( V_116 , V_118 -> V_116 ) ;
if ( V_114 != F_3 ( V_118 -> V_114 ) )
continue;
if ( memcmp ( V_118 -> V_131 , V_115 , V_130 ) == 0 ) {
V_75 = - V_80 ;
break;
}
}
if ( V_75 ) {
F_41 ( V_119 ) ;
goto V_34;
}
memcpy ( V_119 -> V_131 , V_115 , V_116 ) ;
V_119 -> V_116 = V_116 ;
V_119 -> V_132 = V_113 ;
V_119 -> V_114 = F_70 ( V_114 ) ;
F_71 ( & V_119 -> V_133 , & V_6 -> V_134 ) ;
if ( V_10 -> V_84 -> V_135 )
V_10 -> V_84 -> V_135 ( V_8 , V_6 -> V_136 ,
V_114 , true ) ;
V_34:
F_72 ( & V_6 -> V_129 ) ;
return V_75 ;
}
void F_73 ( struct V_5 * V_6 , T_5 V_132 )
{
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_117 * V_118 , * V_137 ;
F_67 ( & V_6 -> V_129 ) ;
F_74 (reg, tmp, &wdev->mgmt_registrations, list) {
if ( V_118 -> V_132 != V_132 )
continue;
if ( V_10 -> V_84 -> V_135 ) {
T_3 V_114 = F_3 ( V_118 -> V_114 ) ;
V_10 -> V_84 -> V_135 ( V_8 , V_6 -> V_136 ,
V_114 , false ) ;
}
F_75 ( & V_118 -> V_133 ) ;
F_41 ( V_118 ) ;
}
F_72 ( & V_6 -> V_129 ) ;
if ( V_132 == V_6 -> V_138 )
V_6 -> V_138 = 0 ;
}
void F_76 ( struct V_5 * V_6 )
{
struct V_117 * V_118 , * V_137 ;
F_67 ( & V_6 -> V_129 ) ;
F_74 (reg, tmp, &wdev->mgmt_registrations, list) {
F_75 ( & V_118 -> V_133 ) ;
F_41 ( V_118 ) ;
}
F_72 ( & V_6 -> V_129 ) ;
}
int F_77 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_62 * V_63 , bool V_139 ,
enum V_107 V_108 ,
bool V_140 , unsigned int V_141 ,
const T_1 * V_3 , T_2 V_4 , bool V_142 ,
bool V_143 , T_6 * V_106 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
const struct V_11 * V_12 ;
T_3 V_144 ;
if ( ! V_6 -> V_8 -> V_121 )
return - V_122 ;
if ( ! V_10 -> V_84 -> V_145 )
return - V_122 ;
if ( V_4 < 24 + 1 )
return - V_79 ;
V_12 = ( const struct V_11 * ) V_3 ;
if ( ! F_78 ( V_12 -> V_146 ) )
return - V_79 ;
V_144 = F_3 ( V_12 -> V_146 ) & V_125 ;
if ( ! ( V_6 -> V_8 -> V_121 [ V_6 -> V_126 ] . V_147 & F_65 ( V_144 >> 4 ) ) )
return - V_79 ;
if ( F_79 ( V_12 -> V_146 ) &&
V_12 -> V_16 . V_148 . V_149 != V_150 ) {
int V_75 = 0 ;
F_4 ( V_6 ) ;
switch ( V_6 -> V_126 ) {
case V_151 :
case V_152 :
case V_153 :
if ( ! V_6 -> V_40 ) {
V_75 = - V_100 ;
break;
}
if ( memcmp ( V_6 -> V_40 -> V_22 . V_13 ,
V_12 -> V_13 , V_23 ) ) {
V_75 = - V_100 ;
break;
}
if ( V_6 -> V_126 == V_151 )
break;
if ( memcmp ( V_6 -> V_40 -> V_22 . V_13 ,
V_12 -> V_154 , V_23 ) ) {
V_75 = - V_100 ;
break;
}
break;
case V_155 :
case V_156 :
case V_157 :
if ( memcmp ( V_12 -> V_13 , V_2 -> V_42 , V_23 ) )
V_75 = - V_79 ;
break;
case V_158 :
if ( memcmp ( V_12 -> V_41 , V_12 -> V_13 , V_23 ) ) {
V_75 = - V_79 ;
break;
}
break;
default:
V_75 = - V_122 ;
break;
}
F_9 ( V_6 ) ;
if ( V_75 )
return V_75 ;
}
if ( memcmp ( V_12 -> V_41 , V_2 -> V_42 , V_23 ) != 0 )
return - V_79 ;
return V_10 -> V_84 -> V_145 ( & V_10 -> V_8 , V_2 , V_63 , V_139 ,
V_108 , V_140 ,
V_141 , V_3 , V_4 , V_142 , V_143 ,
V_106 ) ;
}
bool F_80 ( struct V_1 * V_2 , int V_159 , const T_1 * V_3 ,
T_2 V_4 , T_4 V_55 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_117 * V_118 ;
const struct V_160 * V_161 =
& V_8 -> V_121 [ V_6 -> V_126 ] ;
struct V_11 * V_12 = ( void * ) V_3 ;
const T_1 * V_59 ;
int V_162 ;
bool V_163 = false ;
T_7 V_164 = V_12 -> V_146 &
F_70 ( V_123 | V_125 ) ;
T_3 V_144 ;
V_144 = ( F_3 ( V_12 -> V_146 ) & V_125 ) >> 4 ;
if ( ! ( V_161 -> V_127 & F_65 ( V_144 ) ) )
return false ;
V_59 = V_3 + F_81 ( V_12 -> V_146 ) ;
V_162 = V_4 - F_81 ( V_12 -> V_146 ) ;
F_67 ( & V_6 -> V_129 ) ;
F_68 (reg, &wdev->mgmt_registrations, list) {
if ( V_118 -> V_114 != V_164 )
continue;
if ( V_118 -> V_116 > V_162 )
continue;
if ( memcmp ( V_118 -> V_131 , V_59 , V_118 -> V_116 ) )
continue;
if ( F_82 ( V_10 , V_2 , V_118 -> V_132 , V_159 ,
V_3 , V_4 , V_55 ) )
continue;
V_163 = true ;
break;
}
F_72 ( & V_6 -> V_129 ) ;
return V_163 ;
}
void F_83 ( struct V_1 * V_2 , T_6 V_106 ,
const T_1 * V_3 , T_2 V_4 , bool V_165 , T_4 V_55 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_84 ( V_10 , V_2 , V_106 , V_3 , V_4 , V_165 , V_55 ) ;
}
void F_85 ( struct V_1 * V_2 ,
enum V_166 V_167 ,
T_4 V_55 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_86 ( V_10 , V_2 , V_167 , V_55 ) ;
}
void F_87 ( struct V_1 * V_2 ,
const T_1 * V_168 , T_5 V_169 , T_4 V_55 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_88 ( V_10 , V_2 , V_168 , V_169 , V_55 ) ;
}
void F_89 ( struct V_1 * V_2 , const T_1 * V_13 ,
const T_1 * V_170 , T_4 V_55 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_90 ( V_10 , V_2 , V_13 , V_170 , V_55 ) ;
}
void F_91 ( struct V_1 * V_2 , int V_171 ,
const T_1 * V_13 , bool V_172 , T_4 V_55 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_92 ( V_10 , V_2 , V_171 , V_13 , V_172 , V_55 ) ;
}
bool F_93 ( struct V_1 * V_2 ,
const T_1 * V_50 , T_4 V_55 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( F_25 ( V_6 -> V_126 != V_155 &&
V_6 -> V_126 != V_156 ) )
return false ;
return F_94 ( V_2 , V_50 , V_55 ) ;
}
bool F_95 ( struct V_1 * V_2 ,
const T_1 * V_50 , T_4 V_55 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( F_25 ( V_6 -> V_126 != V_155 &&
V_6 -> V_126 != V_156 &&
V_6 -> V_126 != V_157 ) )
return false ;
return F_96 ( V_2 , V_50 , V_55 ) ;
}
