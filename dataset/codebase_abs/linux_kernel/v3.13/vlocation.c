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
F_12 ( V_35 ) ;
}
continue;
}
break;
case - V_14 :
V_2 -> V_36 ++ ;
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
if ( V_11 < 0 && V_2 -> V_36 > 0 ) {
F_13 ( V_37 L_5
L_6 ,
V_2 -> V_5 . V_12 ) ;
V_2 -> V_38 = 0 ;
V_11 = - V_14 ;
}
F_6 ( & V_2 -> V_7 -> V_13 ) ;
F_7 ( L_3 , V_11 ) ;
return V_11 ;
}
static struct V_1 * F_14 ( struct V_6 * V_7 ,
const char * V_12 ,
T_3 V_39 )
{
struct V_1 * V_2 ;
V_2 = F_15 ( sizeof( struct V_1 ) , V_40 ) ;
if ( V_2 ) {
V_2 -> V_7 = V_7 ;
V_2 -> V_41 = V_42 ;
F_16 ( & V_2 -> V_43 , 1 ) ;
F_17 ( & V_2 -> V_44 ) ;
F_17 ( & V_2 -> V_45 ) ;
F_17 ( & V_2 -> V_46 ) ;
F_18 ( & V_2 -> V_47 ) ;
F_19 ( & V_2 -> V_48 ) ;
memcpy ( V_2 -> V_5 . V_12 , V_12 , V_39 ) ;
}
F_7 ( L_7 , V_2 ) ;
return V_2 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_3 * V_3 ,
struct V_4 * V_5 )
{
T_2 V_31 ;
T_1 V_49 ;
int V_11 ;
F_4 ( L_8 ,
V_2 -> V_5 . V_12 ,
V_2 -> V_5 . V_50 ,
F_21 ( V_2 -> V_5 . V_51 [ 0 ] . V_18 ) ,
V_2 -> V_5 . V_52 [ 0 ] ,
F_21 ( V_2 -> V_5 . V_51 [ 1 ] . V_18 ) ,
V_2 -> V_5 . V_52 [ 1 ] ,
F_21 ( V_2 -> V_5 . V_51 [ 2 ] . V_18 ) ,
V_2 -> V_5 . V_52 [ 2 ] ) ;
F_4 ( L_9 ,
V_2 -> V_5 . V_49 [ 0 ] ,
V_2 -> V_5 . V_49 [ 1 ] ,
V_2 -> V_5 . V_49 [ 2 ] ) ;
if ( V_2 -> V_5 . V_50 & V_53 ) {
V_49 = V_2 -> V_5 . V_49 [ 0 ] ;
V_31 = V_54 ;
} else if ( V_2 -> V_5 . V_50 & V_55 ) {
V_49 = V_2 -> V_5 . V_49 [ 1 ] ;
V_31 = V_56 ;
} else if ( V_2 -> V_5 . V_50 & V_57 ) {
V_49 = V_2 -> V_5 . V_49 [ 2 ] ;
V_31 = V_58 ;
} else {
F_22 () ;
V_49 = 0 ;
V_31 = 0 ;
}
V_11 = F_8 ( V_2 , V_3 , V_49 , V_31 , V_5 ) ;
switch ( V_11 ) {
default:
F_13 ( V_59 L_5
L_10 ,
V_2 -> V_5 . V_12 , V_49 , V_2 -> V_7 -> V_12 , V_11 ) ;
F_7 ( L_3 , V_11 ) ;
return V_11 ;
case 0 :
F_7 ( L_11 ) ;
return 0 ;
case - V_14 :
F_13 ( V_60 L_5
L_12 ,
V_2 -> V_5 . V_12 , V_49 , V_2 -> V_7 -> V_12 ) ;
F_7 ( L_3 , V_11 ) ;
return V_11 ;
}
}
static void F_23 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
F_4 ( L_13 ,
V_5 -> V_12 , V_5 -> V_50 ,
F_21 ( V_5 -> V_51 [ 0 ] . V_18 ) , V_5 -> V_52 [ 0 ] ,
F_21 ( V_5 -> V_51 [ 1 ] . V_18 ) , V_5 -> V_52 [ 1 ] ,
F_21 ( V_5 -> V_51 [ 2 ] . V_18 ) , V_5 -> V_52 [ 2 ] ) ;
F_4 ( L_9 ,
V_5 -> V_49 [ 0 ] , V_5 -> V_49 [ 1 ] , V_5 -> V_49 [ 2 ] ) ;
if ( strcmp ( V_5 -> V_12 , V_2 -> V_5 . V_12 ) != 0 )
F_13 ( V_37 L_5
L_14 ,
V_2 -> V_5 . V_12 , V_5 -> V_12 ) ;
V_2 -> V_5 = * V_5 ;
#ifdef F_24
F_25 ( V_2 -> V_61 ) ;
#endif
}
static int F_26 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
struct V_4 V_5 ;
int V_11 ;
F_2 ( L_15 ) ;
F_27 ( V_2 -> V_38 , == , 0 ) ;
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
#ifdef F_24
V_2 -> V_61 = F_28 ( V_2 -> V_7 -> V_61 ,
& V_62 , V_2 ,
true ) ;
#endif
if ( V_2 -> V_38 ) {
F_4 ( L_16 ) ;
V_11 = F_20 ( V_2 , V_3 , & V_5 ) ;
} else {
V_11 = F_1 ( V_2 , V_3 , & V_5 ) ;
if ( V_11 < 0 ) {
F_13 ( L_17 ,
V_2 -> V_5 . V_12 , V_2 -> V_7 -> V_12 ) ;
return V_11 ;
}
}
F_23 ( V_2 , & V_5 ) ;
F_7 ( L_11 ) ;
return 0 ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_1 * V_63 ;
V_2 -> V_64 = F_30 () + V_65 ;
F_31 ( & V_66 ) ;
if ( ! F_32 ( & V_67 ) ) {
V_63 = F_33 ( V_67 . V_68 ,
struct V_1 , V_46 ) ;
if ( V_2 -> V_64 <= V_63 -> V_64 )
V_2 -> V_64 = V_63 -> V_64 + 1 ;
} else {
F_34 ( V_69 ,
& V_70 ,
V_65 * V_71 ) ;
}
F_35 ( & V_2 -> V_46 , & V_67 ) ;
F_36 ( & V_66 ) ;
}
struct V_1 * F_37 ( struct V_6 * V_7 ,
struct V_3 * V_3 ,
const char * V_12 ,
T_3 V_39 )
{
struct V_1 * V_2 ;
int V_11 ;
F_2 ( L_18 ,
V_7 -> V_12 , F_38 ( V_3 ) ,
( int ) V_39 , ( int ) V_39 , V_12 , V_39 ) ;
if ( V_39 >= sizeof( V_2 -> V_5 . V_12 ) ) {
F_7 ( L_19 ) ;
return F_39 ( - V_72 ) ;
}
F_3 ( & V_7 -> V_13 ) ;
F_31 ( & V_7 -> V_73 ) ;
F_40 (vl, &cell->vl_list, link) {
if ( V_2 -> V_5 . V_12 [ V_39 ] != '\0' )
continue;
if ( memcmp ( V_2 -> V_5 . V_12 , V_12 , V_39 ) == 0 )
goto V_74;
}
F_36 ( & V_7 -> V_73 ) ;
V_2 = F_14 ( V_7 , V_12 , V_39 ) ;
if ( ! V_2 ) {
F_6 ( & V_7 -> V_13 ) ;
return F_39 ( - V_21 ) ;
}
F_41 ( V_7 ) ;
F_35 ( & V_2 -> V_44 , & V_7 -> V_75 ) ;
V_2 -> V_41 = V_76 ;
F_6 ( & V_7 -> V_13 ) ;
V_77:
V_11 = F_26 ( V_2 , V_3 ) ;
if ( V_11 < 0 )
goto V_78;
F_31 ( & V_2 -> V_48 ) ;
V_2 -> V_41 = V_79 ;
F_36 ( & V_2 -> V_48 ) ;
F_42 ( & V_2 -> V_47 ) ;
#ifdef F_24
F_25 ( V_2 -> V_61 ) ;
#endif
F_29 ( V_2 ) ;
goto V_80;
V_74:
F_4 ( L_20 ) ;
F_43 ( & V_2 -> V_43 ) ;
F_36 ( & V_7 -> V_73 ) ;
if ( ! F_32 ( & V_2 -> V_45 ) ) {
F_31 ( & V_81 ) ;
F_44 ( & V_2 -> V_45 ) ;
F_36 ( & V_81 ) ;
}
F_6 ( & V_7 -> V_13 ) ;
F_31 ( & V_2 -> V_48 ) ;
while ( V_2 -> V_41 != V_79 ) {
T_4 V_41 = V_2 -> V_41 ;
F_4 ( L_21 , V_41 ) ;
if ( V_41 == V_42 || V_41 == V_82 ) {
V_2 -> V_41 = V_76 ;
F_36 ( & V_2 -> V_48 ) ;
goto V_77;
}
F_4 ( L_22 ) ;
F_36 ( & V_2 -> V_48 ) ;
V_11 = F_45 ( V_2 -> V_47 ,
V_2 -> V_41 == V_42 ||
V_2 -> V_41 == V_79 ||
V_2 -> V_41 == V_82 ) ;
if ( V_11 < 0 )
goto error;
F_31 ( & V_2 -> V_48 ) ;
}
F_36 ( & V_2 -> V_48 ) ;
V_80:
F_7 ( L_7 , V_2 ) ;
return V_2 ;
V_78:
F_31 ( & V_2 -> V_48 ) ;
V_2 -> V_41 = V_42 ;
F_36 ( & V_2 -> V_48 ) ;
F_42 ( & V_2 -> V_47 ) ;
error:
ASSERT ( V_2 != NULL ) ;
F_46 ( V_2 ) ;
F_7 ( L_3 , V_11 ) ;
return F_39 ( V_11 ) ;
}
void F_46 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_2 ( L_23 , V_2 -> V_5 . V_12 ) ;
F_27 ( F_47 ( & V_2 -> V_43 ) , > , 0 ) ;
if ( F_48 ( ! F_49 ( & V_2 -> V_43 ) ) ) {
F_7 ( L_15 ) ;
return;
}
F_31 ( & V_81 ) ;
if ( F_47 ( & V_2 -> V_43 ) == 0 ) {
F_4 ( L_24 ) ;
F_50 ( & V_2 -> V_45 , & V_83 ) ;
V_2 -> V_84 = F_30 () ;
F_34 ( V_85 , & V_86 ,
V_87 * V_71 ) ;
if ( ! F_32 ( & V_2 -> V_46 ) ) {
F_31 ( & V_66 ) ;
F_44 ( & V_2 -> V_46 ) ;
F_36 ( & V_66 ) ;
}
}
F_36 ( & V_81 ) ;
F_7 ( L_25 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
F_2 ( L_26 , V_2 ) ;
#ifdef F_24
F_52 ( V_2 -> V_61 , 0 ) ;
#endif
F_53 ( V_2 -> V_7 ) ;
F_54 ( V_2 ) ;
}
static void F_55 ( struct V_88 * V_89 )
{
F_56 ( V_90 ) ;
struct V_1 * V_2 ;
unsigned long V_91 , V_92 ;
T_5 V_93 ;
F_2 ( L_15 ) ;
V_93 = F_30 () ;
F_31 ( & V_81 ) ;
while ( ! F_32 ( & V_83 ) ) {
V_2 = F_33 ( V_83 . V_94 ,
struct V_1 , V_45 ) ;
F_4 ( L_27 , V_2 ) ;
V_92 = V_2 -> V_84 + V_87 ;
if ( V_92 > V_93 ) {
V_91 = ( V_92 - V_93 ) * V_71 ;
F_4 ( L_28 , V_91 ) ;
F_57 ( V_85 , & V_86 , V_91 ) ;
break;
}
F_31 ( & V_2 -> V_7 -> V_73 ) ;
if ( F_47 ( & V_2 -> V_43 ) > 0 ) {
F_4 ( L_29 ) ;
F_44 ( & V_2 -> V_45 ) ;
} else {
F_4 ( L_30 ) ;
F_50 ( & V_2 -> V_45 , & V_90 ) ;
F_44 ( & V_2 -> V_44 ) ;
}
F_36 ( & V_2 -> V_7 -> V_73 ) ;
}
F_36 ( & V_81 ) ;
while ( ! F_32 ( & V_90 ) ) {
V_2 = F_33 ( V_90 . V_94 , struct V_1 , V_45 ) ;
F_58 ( & V_2 -> V_45 ) ;
F_51 ( V_2 ) ;
}
F_7 ( L_15 ) ;
}
int T_6 F_59 ( void )
{
V_69 =
F_60 ( L_31 ) ;
return V_69 ? 0 : - V_21 ;
}
void F_61 ( void )
{
V_87 = 0 ;
F_31 ( & V_66 ) ;
F_44 ( & V_67 ) ;
F_36 ( & V_66 ) ;
F_57 ( V_69 , & V_70 , 0 ) ;
F_62 ( V_69 ) ;
F_57 ( V_85 , & V_86 , 0 ) ;
}
static void F_63 ( struct V_88 * V_89 )
{
struct V_4 V_5 ;
struct V_1 * V_2 , * V_63 ;
T_5 V_93 ;
long V_95 ;
int V_11 ;
F_2 ( L_15 ) ;
V_93 = F_30 () ;
F_31 ( & V_66 ) ;
for (; ; ) {
if ( F_32 ( & V_67 ) ) {
F_36 ( & V_66 ) ;
F_7 ( L_32 ) ;
return;
}
V_2 = F_33 ( V_67 . V_94 ,
struct V_1 , V_46 ) ;
if ( F_47 ( & V_2 -> V_43 ) > 0 )
break;
F_44 ( & V_2 -> V_46 ) ;
}
V_95 = V_2 -> V_64 - V_93 ;
if ( V_95 > 0 ) {
F_34 ( V_69 ,
& V_70 , V_95 * V_71 ) ;
F_36 ( & V_66 ) ;
F_7 ( L_32 ) ;
return;
}
F_44 ( & V_2 -> V_46 ) ;
F_43 ( & V_2 -> V_43 ) ;
F_36 ( & V_66 ) ;
F_4 ( L_33 , V_2 -> V_5 . V_12 ) ;
V_2 -> V_41 = V_96 ;
V_2 -> V_36 = 0 ;
V_2 -> V_33 = 0 ;
V_11 = F_20 ( V_2 , NULL , & V_5 ) ;
F_31 ( & V_2 -> V_48 ) ;
switch ( V_11 ) {
case 0 :
F_23 ( V_2 , & V_5 ) ;
V_2 -> V_41 = V_79 ;
break;
case - V_14 :
V_2 -> V_41 = V_97 ;
break;
default:
V_2 -> V_41 = V_98 ;
break;
}
F_36 ( & V_2 -> V_48 ) ;
F_42 ( & V_2 -> V_47 ) ;
F_4 ( L_34 ) ;
V_2 -> V_64 = F_30 () + V_65 ;
F_31 ( & V_66 ) ;
if ( ! F_32 ( & V_67 ) ) {
V_63 = F_33 ( V_67 . V_68 ,
struct V_1 , V_46 ) ;
if ( V_2 -> V_64 <= V_63 -> V_64 )
V_2 -> V_64 = V_63 -> V_64 + 1 ;
V_63 = F_33 ( V_67 . V_94 ,
struct V_1 , V_46 ) ;
V_95 = V_63 -> V_64 - V_93 ;
if ( V_95 < 0 )
V_95 = 0 ;
} else {
V_95 = V_65 ;
}
ASSERT ( F_32 ( & V_2 -> V_46 ) ) ;
F_35 ( & V_2 -> V_46 , & V_67 ) ;
F_4 ( L_35 , V_95 ) ;
F_34 ( V_69 ,
& V_70 , V_95 * V_71 ) ;
F_36 ( & V_66 ) ;
F_46 ( V_2 ) ;
}
