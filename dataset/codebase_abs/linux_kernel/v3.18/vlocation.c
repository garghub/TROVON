static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 V_9 ;
int V_10 , V_11 ;
F_2 ( L_1 , V_7 -> V_12 , V_2 -> V_5 . V_12 ) ;
F_3 ( & V_2 -> V_7 -> V_13 ) ;
V_11 = - V_14 ;
for ( V_10 = V_7 -> V_15 ; V_10 > 0 ; V_10 -- ) {
V_9 = V_7 -> V_16 [ V_7 -> V_17 ] ;
F_4 ( L_2 , V_7 -> V_17 , V_9 . V_18 ) ;
V_11 = F_5 ( & V_9 , V_3 , V_2 -> V_5 . V_12 , V_5 ,
& V_19 ) ;
switch ( V_11 ) {
case 0 :
goto V_20;
case - V_21 :
case - V_22 :
case - V_23 :
case - V_24 :
case - V_25 :
if ( V_11 == - V_21 || V_11 == - V_22 )
goto V_20;
goto V_26;
case - V_14 :
case - V_27 :
case - V_28 :
goto V_20;
default:
V_11 = - V_29 ;
goto V_26;
}
V_26:
V_7 -> V_17 ++ ;
V_7 -> V_17 %= V_7 -> V_15 ;
}
V_20:
F_6 ( & V_2 -> V_7 -> V_13 ) ;
F_7 ( L_3 , V_11 ) ;
return V_11 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_3 ,
T_1 V_30 ,
T_2 V_31 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 V_9 ;
int V_10 , V_11 ;
F_2 ( L_4 , V_7 -> V_12 , V_30 , V_31 ) ;
F_3 ( & V_2 -> V_7 -> V_13 ) ;
V_11 = - V_14 ;
for ( V_10 = V_7 -> V_15 ; V_10 > 0 ; V_10 -- ) {
V_9 = V_7 -> V_16 [ V_7 -> V_17 ] ;
F_4 ( L_2 , V_7 -> V_17 , V_9 . V_18 ) ;
V_11 = F_9 ( & V_9 , V_3 , V_30 , V_31 , V_5 ,
& V_19 ) ;
switch ( V_11 ) {
case 0 :
goto V_20;
case - V_21 :
case - V_22 :
case - V_23 :
case - V_24 :
case - V_25 :
if ( V_11 == - V_21 || V_11 == - V_22 )
goto V_20;
goto V_26;
case - V_32 :
V_2 -> V_33 ++ ;
if ( V_2 -> V_33 <= 3 ) {
if ( V_2 -> V_33 > 1 ) {
F_10 ( V_34 ) ;
F_11 ( 1 ) ;
}
continue;
}
break;
case - V_14 :
V_2 -> V_35 ++ ;
goto V_26;
default:
V_11 = - V_29 ;
goto V_26;
}
V_26:
V_7 -> V_17 ++ ;
V_7 -> V_17 %= V_7 -> V_15 ;
V_2 -> V_33 = 0 ;
}
V_20:
if ( V_11 < 0 && V_2 -> V_35 > 0 ) {
F_12 ( V_36 L_5
L_6 ,
V_2 -> V_5 . V_12 ) ;
V_2 -> V_37 = 0 ;
V_11 = - V_14 ;
}
F_6 ( & V_2 -> V_7 -> V_13 ) ;
F_7 ( L_3 , V_11 ) ;
return V_11 ;
}
static struct V_1 * F_13 ( struct V_6 * V_7 ,
const char * V_12 ,
T_3 V_38 )
{
struct V_1 * V_2 ;
V_2 = F_14 ( sizeof( struct V_1 ) , V_39 ) ;
if ( V_2 ) {
V_2 -> V_7 = V_7 ;
V_2 -> V_40 = V_41 ;
F_15 ( & V_2 -> V_42 , 1 ) ;
F_16 ( & V_2 -> V_43 ) ;
F_16 ( & V_2 -> V_44 ) ;
F_16 ( & V_2 -> V_45 ) ;
F_17 ( & V_2 -> V_46 ) ;
F_18 ( & V_2 -> V_47 ) ;
memcpy ( V_2 -> V_5 . V_12 , V_12 , V_38 ) ;
}
F_7 ( L_7 , V_2 ) ;
return V_2 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_3 ,
struct V_4 * V_5 )
{
T_2 V_31 ;
T_1 V_48 ;
int V_11 ;
F_4 ( L_8 ,
V_2 -> V_5 . V_12 ,
V_2 -> V_5 . V_49 ,
F_20 ( V_2 -> V_5 . V_50 [ 0 ] . V_18 ) ,
V_2 -> V_5 . V_51 [ 0 ] ,
F_20 ( V_2 -> V_5 . V_50 [ 1 ] . V_18 ) ,
V_2 -> V_5 . V_51 [ 1 ] ,
F_20 ( V_2 -> V_5 . V_50 [ 2 ] . V_18 ) ,
V_2 -> V_5 . V_51 [ 2 ] ) ;
F_4 ( L_9 ,
V_2 -> V_5 . V_48 [ 0 ] ,
V_2 -> V_5 . V_48 [ 1 ] ,
V_2 -> V_5 . V_48 [ 2 ] ) ;
if ( V_2 -> V_5 . V_49 & V_52 ) {
V_48 = V_2 -> V_5 . V_48 [ 0 ] ;
V_31 = V_53 ;
} else if ( V_2 -> V_5 . V_49 & V_54 ) {
V_48 = V_2 -> V_5 . V_48 [ 1 ] ;
V_31 = V_55 ;
} else if ( V_2 -> V_5 . V_49 & V_56 ) {
V_48 = V_2 -> V_5 . V_48 [ 2 ] ;
V_31 = V_57 ;
} else {
F_21 () ;
V_48 = 0 ;
V_31 = 0 ;
}
V_11 = F_8 ( V_2 , V_3 , V_48 , V_31 , V_5 ) ;
switch ( V_11 ) {
default:
F_12 ( V_58 L_5
L_10 ,
V_2 -> V_5 . V_12 , V_48 , V_2 -> V_7 -> V_12 , V_11 ) ;
F_7 ( L_3 , V_11 ) ;
return V_11 ;
case 0 :
F_7 ( L_11 ) ;
return 0 ;
case - V_14 :
F_12 ( V_59 L_5
L_12 ,
V_2 -> V_5 . V_12 , V_48 , V_2 -> V_7 -> V_12 ) ;
F_7 ( L_3 , V_11 ) ;
return V_11 ;
}
}
static void F_22 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
F_4 ( L_13 ,
V_5 -> V_12 , V_5 -> V_49 ,
F_20 ( V_5 -> V_50 [ 0 ] . V_18 ) , V_5 -> V_51 [ 0 ] ,
F_20 ( V_5 -> V_50 [ 1 ] . V_18 ) , V_5 -> V_51 [ 1 ] ,
F_20 ( V_5 -> V_50 [ 2 ] . V_18 ) , V_5 -> V_51 [ 2 ] ) ;
F_4 ( L_9 ,
V_5 -> V_48 [ 0 ] , V_5 -> V_48 [ 1 ] , V_5 -> V_48 [ 2 ] ) ;
if ( strcmp ( V_5 -> V_12 , V_2 -> V_5 . V_12 ) != 0 )
F_12 ( V_36 L_5
L_14 ,
V_2 -> V_5 . V_12 , V_5 -> V_12 ) ;
V_2 -> V_5 = * V_5 ;
#ifdef F_23
F_24 ( V_2 -> V_60 ) ;
#endif
}
static int F_25 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
struct V_4 V_5 ;
int V_11 ;
F_2 ( L_15 ) ;
F_26 ( V_2 -> V_37 , == , 0 ) ;
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
#ifdef F_23
V_2 -> V_60 = F_27 ( V_2 -> V_7 -> V_60 ,
& V_61 , V_2 ,
true ) ;
#endif
if ( V_2 -> V_37 ) {
F_4 ( L_16 ) ;
V_11 = F_19 ( V_2 , V_3 , & V_5 ) ;
} else {
V_11 = F_1 ( V_2 , V_3 , & V_5 ) ;
if ( V_11 < 0 ) {
F_12 ( L_17 ,
V_2 -> V_5 . V_12 , V_2 -> V_7 -> V_12 ) ;
return V_11 ;
}
}
F_22 ( V_2 , & V_5 ) ;
F_7 ( L_11 ) ;
return 0 ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_1 * V_62 ;
V_2 -> V_63 = F_29 () + V_64 ;
F_30 ( & V_65 ) ;
if ( ! F_31 ( & V_66 ) ) {
V_62 = F_32 ( V_66 . V_67 ,
struct V_1 , V_45 ) ;
if ( V_2 -> V_63 <= V_62 -> V_63 )
V_2 -> V_63 = V_62 -> V_63 + 1 ;
} else {
F_33 ( V_68 ,
& V_69 ,
V_64 * V_70 ) ;
}
F_34 ( & V_2 -> V_45 , & V_66 ) ;
F_35 ( & V_65 ) ;
}
struct V_1 * F_36 ( struct V_6 * V_7 ,
struct V_3 * V_3 ,
const char * V_12 ,
T_3 V_38 )
{
struct V_1 * V_2 ;
int V_11 ;
F_2 ( L_18 ,
V_7 -> V_12 , F_37 ( V_3 ) ,
( int ) V_38 , ( int ) V_38 , V_12 , V_38 ) ;
if ( V_38 >= sizeof( V_2 -> V_5 . V_12 ) ) {
F_7 ( L_19 ) ;
return F_38 ( - V_71 ) ;
}
F_3 ( & V_7 -> V_13 ) ;
F_30 ( & V_7 -> V_72 ) ;
F_39 (vl, &cell->vl_list, link) {
if ( V_2 -> V_5 . V_12 [ V_38 ] != '\0' )
continue;
if ( memcmp ( V_2 -> V_5 . V_12 , V_12 , V_38 ) == 0 )
goto V_73;
}
F_35 ( & V_7 -> V_72 ) ;
V_2 = F_13 ( V_7 , V_12 , V_38 ) ;
if ( ! V_2 ) {
F_6 ( & V_7 -> V_13 ) ;
return F_38 ( - V_21 ) ;
}
F_40 ( V_7 ) ;
F_34 ( & V_2 -> V_43 , & V_7 -> V_74 ) ;
V_2 -> V_40 = V_75 ;
F_6 ( & V_7 -> V_13 ) ;
V_76:
V_11 = F_25 ( V_2 , V_3 ) ;
if ( V_11 < 0 )
goto V_77;
F_30 ( & V_2 -> V_47 ) ;
V_2 -> V_40 = V_78 ;
F_35 ( & V_2 -> V_47 ) ;
F_41 ( & V_2 -> V_46 ) ;
#ifdef F_23
F_24 ( V_2 -> V_60 ) ;
#endif
F_28 ( V_2 ) ;
goto V_79;
V_73:
F_4 ( L_20 ) ;
F_42 ( & V_2 -> V_42 ) ;
F_35 ( & V_7 -> V_72 ) ;
if ( ! F_31 ( & V_2 -> V_44 ) ) {
F_30 ( & V_80 ) ;
F_43 ( & V_2 -> V_44 ) ;
F_35 ( & V_80 ) ;
}
F_6 ( & V_7 -> V_13 ) ;
F_30 ( & V_2 -> V_47 ) ;
while ( V_2 -> V_40 != V_78 ) {
T_4 V_40 = V_2 -> V_40 ;
F_4 ( L_21 , V_40 ) ;
if ( V_40 == V_41 || V_40 == V_81 ) {
V_2 -> V_40 = V_75 ;
F_35 ( & V_2 -> V_47 ) ;
goto V_76;
}
F_4 ( L_22 ) ;
F_35 ( & V_2 -> V_47 ) ;
V_11 = F_44 ( V_2 -> V_46 ,
V_2 -> V_40 == V_41 ||
V_2 -> V_40 == V_78 ||
V_2 -> V_40 == V_81 ) ;
if ( V_11 < 0 )
goto error;
F_30 ( & V_2 -> V_47 ) ;
}
F_35 ( & V_2 -> V_47 ) ;
V_79:
F_7 ( L_7 , V_2 ) ;
return V_2 ;
V_77:
F_30 ( & V_2 -> V_47 ) ;
V_2 -> V_40 = V_41 ;
F_35 ( & V_2 -> V_47 ) ;
F_41 ( & V_2 -> V_46 ) ;
error:
ASSERT ( V_2 != NULL ) ;
F_45 ( V_2 ) ;
F_7 ( L_3 , V_11 ) ;
return F_38 ( V_11 ) ;
}
void F_45 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_2 ( L_23 , V_2 -> V_5 . V_12 ) ;
F_26 ( F_46 ( & V_2 -> V_42 ) , > , 0 ) ;
if ( F_47 ( ! F_48 ( & V_2 -> V_42 ) ) ) {
F_7 ( L_15 ) ;
return;
}
F_30 ( & V_80 ) ;
if ( F_46 ( & V_2 -> V_42 ) == 0 ) {
F_4 ( L_24 ) ;
F_49 ( & V_2 -> V_44 , & V_82 ) ;
V_2 -> V_83 = F_29 () ;
F_33 ( V_84 , & V_85 ,
V_86 * V_70 ) ;
if ( ! F_31 ( & V_2 -> V_45 ) ) {
F_30 ( & V_65 ) ;
F_43 ( & V_2 -> V_45 ) ;
F_35 ( & V_65 ) ;
}
}
F_35 ( & V_80 ) ;
F_7 ( L_25 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
F_2 ( L_26 , V_2 ) ;
#ifdef F_23
F_51 ( V_2 -> V_60 , 0 ) ;
#endif
F_52 ( V_2 -> V_7 ) ;
F_53 ( V_2 ) ;
}
static void F_54 ( struct V_87 * V_88 )
{
F_55 ( V_89 ) ;
struct V_1 * V_2 ;
unsigned long V_90 , V_91 ;
T_5 V_92 ;
F_2 ( L_15 ) ;
V_92 = F_29 () ;
F_30 ( & V_80 ) ;
while ( ! F_31 ( & V_82 ) ) {
V_2 = F_32 ( V_82 . V_93 ,
struct V_1 , V_44 ) ;
F_4 ( L_27 , V_2 ) ;
V_91 = V_2 -> V_83 + V_86 ;
if ( V_91 > V_92 ) {
V_90 = ( V_91 - V_92 ) * V_70 ;
F_4 ( L_28 , V_90 ) ;
F_56 ( V_84 , & V_85 , V_90 ) ;
break;
}
F_30 ( & V_2 -> V_7 -> V_72 ) ;
if ( F_46 ( & V_2 -> V_42 ) > 0 ) {
F_4 ( L_29 ) ;
F_43 ( & V_2 -> V_44 ) ;
} else {
F_4 ( L_30 ) ;
F_49 ( & V_2 -> V_44 , & V_89 ) ;
F_43 ( & V_2 -> V_43 ) ;
}
F_35 ( & V_2 -> V_7 -> V_72 ) ;
}
F_35 ( & V_80 ) ;
while ( ! F_31 ( & V_89 ) ) {
V_2 = F_32 ( V_89 . V_93 , struct V_1 , V_44 ) ;
F_57 ( & V_2 -> V_44 ) ;
F_50 ( V_2 ) ;
}
F_7 ( L_15 ) ;
}
int T_6 F_58 ( void )
{
V_68 =
F_59 ( L_31 ) ;
return V_68 ? 0 : - V_21 ;
}
void F_60 ( void )
{
V_86 = 0 ;
F_30 ( & V_65 ) ;
F_43 ( & V_66 ) ;
F_35 ( & V_65 ) ;
F_56 ( V_68 , & V_69 , 0 ) ;
F_61 ( V_68 ) ;
F_56 ( V_84 , & V_85 , 0 ) ;
}
static void F_62 ( struct V_87 * V_88 )
{
struct V_4 V_5 ;
struct V_1 * V_2 , * V_62 ;
T_5 V_92 ;
long V_94 ;
int V_11 ;
F_2 ( L_15 ) ;
V_92 = F_29 () ;
F_30 ( & V_65 ) ;
for (; ; ) {
if ( F_31 ( & V_66 ) ) {
F_35 ( & V_65 ) ;
F_7 ( L_32 ) ;
return;
}
V_2 = F_32 ( V_66 . V_93 ,
struct V_1 , V_45 ) ;
if ( F_46 ( & V_2 -> V_42 ) > 0 )
break;
F_43 ( & V_2 -> V_45 ) ;
}
V_94 = V_2 -> V_63 - V_92 ;
if ( V_94 > 0 ) {
F_33 ( V_68 ,
& V_69 , V_94 * V_70 ) ;
F_35 ( & V_65 ) ;
F_7 ( L_32 ) ;
return;
}
F_43 ( & V_2 -> V_45 ) ;
F_42 ( & V_2 -> V_42 ) ;
F_35 ( & V_65 ) ;
F_4 ( L_33 , V_2 -> V_5 . V_12 ) ;
V_2 -> V_40 = V_95 ;
V_2 -> V_35 = 0 ;
V_2 -> V_33 = 0 ;
V_11 = F_19 ( V_2 , NULL , & V_5 ) ;
F_30 ( & V_2 -> V_47 ) ;
switch ( V_11 ) {
case 0 :
F_22 ( V_2 , & V_5 ) ;
V_2 -> V_40 = V_78 ;
break;
case - V_14 :
V_2 -> V_40 = V_96 ;
break;
default:
V_2 -> V_40 = V_97 ;
break;
}
F_35 ( & V_2 -> V_47 ) ;
F_41 ( & V_2 -> V_46 ) ;
F_4 ( L_34 ) ;
V_2 -> V_63 = F_29 () + V_64 ;
F_30 ( & V_65 ) ;
if ( ! F_31 ( & V_66 ) ) {
V_62 = F_32 ( V_66 . V_67 ,
struct V_1 , V_45 ) ;
if ( V_2 -> V_63 <= V_62 -> V_63 )
V_2 -> V_63 = V_62 -> V_63 + 1 ;
V_62 = F_32 ( V_66 . V_93 ,
struct V_1 , V_45 ) ;
V_94 = V_62 -> V_63 - V_92 ;
if ( V_94 < 0 )
V_94 = 0 ;
} else {
V_94 = V_64 ;
}
ASSERT ( F_31 ( & V_2 -> V_45 ) ) ;
F_34 ( & V_2 -> V_45 , & V_66 ) ;
F_4 ( L_35 , V_94 ) ;
F_33 ( V_68 ,
& V_69 , V_94 * V_70 ) ;
F_35 ( & V_65 ) ;
F_45 ( V_2 ) ;
}
