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
false ) ;
switch ( V_11 ) {
case 0 :
goto V_19;
case - V_20 :
case - V_21 :
case - V_22 :
case - V_23 :
case - V_24 :
if ( V_11 == - V_20 || V_11 == - V_21 )
goto V_19;
goto V_25;
case - V_14 :
case - V_26 :
case - V_27 :
goto V_19;
default:
V_11 = - V_28 ;
goto V_25;
}
V_25:
V_7 -> V_17 ++ ;
V_7 -> V_17 %= V_7 -> V_15 ;
}
V_19:
F_6 ( & V_2 -> V_7 -> V_13 ) ;
F_7 ( L_3 , V_11 ) ;
return V_11 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_3 ,
T_1 V_29 ,
T_2 V_30 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 V_9 ;
int V_10 , V_11 ;
F_2 ( L_4 , V_7 -> V_12 , V_29 , V_30 ) ;
F_3 ( & V_2 -> V_7 -> V_13 ) ;
V_11 = - V_14 ;
for ( V_10 = V_7 -> V_15 ; V_10 > 0 ; V_10 -- ) {
V_9 = V_7 -> V_16 [ V_7 -> V_17 ] ;
F_4 ( L_2 , V_7 -> V_17 , V_9 . V_18 ) ;
V_11 = F_9 ( & V_9 , V_3 , V_29 , V_30 , V_5 ,
false ) ;
switch ( V_11 ) {
case 0 :
goto V_19;
case - V_20 :
case - V_21 :
case - V_22 :
case - V_23 :
case - V_24 :
if ( V_11 == - V_20 || V_11 == - V_21 )
goto V_19;
goto V_25;
case - V_31 :
V_2 -> V_32 ++ ;
if ( V_2 -> V_32 <= 3 ) {
if ( V_2 -> V_32 > 1 ) {
F_10 ( V_33 ) ;
F_11 ( 1 ) ;
}
continue;
}
break;
case - V_14 :
V_2 -> V_34 ++ ;
goto V_25;
default:
V_11 = - V_28 ;
goto V_25;
}
V_25:
V_7 -> V_17 ++ ;
V_7 -> V_17 %= V_7 -> V_15 ;
V_2 -> V_32 = 0 ;
}
V_19:
if ( V_11 < 0 && V_2 -> V_34 > 0 ) {
F_12 ( V_35 L_5
L_6 ,
V_2 -> V_5 . V_12 ) ;
V_2 -> V_36 = 0 ;
V_11 = - V_14 ;
}
F_6 ( & V_2 -> V_7 -> V_13 ) ;
F_7 ( L_3 , V_11 ) ;
return V_11 ;
}
static struct V_1 * F_13 ( struct V_6 * V_7 ,
const char * V_12 ,
T_3 V_37 )
{
struct V_1 * V_2 ;
V_2 = F_14 ( sizeof( struct V_1 ) , V_38 ) ;
if ( V_2 ) {
V_2 -> V_7 = V_7 ;
V_2 -> V_39 = V_40 ;
F_15 ( & V_2 -> V_41 , 1 ) ;
F_16 ( & V_2 -> V_42 ) ;
F_16 ( & V_2 -> V_43 ) ;
F_16 ( & V_2 -> V_44 ) ;
F_17 ( & V_2 -> V_45 ) ;
F_18 ( & V_2 -> V_46 ) ;
memcpy ( V_2 -> V_5 . V_12 , V_12 , V_37 ) ;
}
F_7 ( L_7 , V_2 ) ;
return V_2 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_3 ,
struct V_4 * V_5 )
{
T_2 V_30 ;
T_1 V_47 ;
int V_11 ;
F_4 ( L_8 ,
V_2 -> V_5 . V_12 ,
V_2 -> V_5 . V_48 ,
F_20 ( V_2 -> V_5 . V_49 [ 0 ] . V_18 ) ,
V_2 -> V_5 . V_50 [ 0 ] ,
F_20 ( V_2 -> V_5 . V_49 [ 1 ] . V_18 ) ,
V_2 -> V_5 . V_50 [ 1 ] ,
F_20 ( V_2 -> V_5 . V_49 [ 2 ] . V_18 ) ,
V_2 -> V_5 . V_50 [ 2 ] ) ;
F_4 ( L_9 ,
V_2 -> V_5 . V_47 [ 0 ] ,
V_2 -> V_5 . V_47 [ 1 ] ,
V_2 -> V_5 . V_47 [ 2 ] ) ;
if ( V_2 -> V_5 . V_48 & V_51 ) {
V_47 = V_2 -> V_5 . V_47 [ 0 ] ;
V_30 = V_52 ;
} else if ( V_2 -> V_5 . V_48 & V_53 ) {
V_47 = V_2 -> V_5 . V_47 [ 1 ] ;
V_30 = V_54 ;
} else if ( V_2 -> V_5 . V_48 & V_55 ) {
V_47 = V_2 -> V_5 . V_47 [ 2 ] ;
V_30 = V_56 ;
} else {
F_21 () ;
V_47 = 0 ;
V_30 = 0 ;
}
V_11 = F_8 ( V_2 , V_3 , V_47 , V_30 , V_5 ) ;
switch ( V_11 ) {
default:
F_12 ( V_57 L_5
L_10 ,
V_2 -> V_5 . V_12 , V_47 , V_2 -> V_7 -> V_12 , V_11 ) ;
F_7 ( L_3 , V_11 ) ;
return V_11 ;
case 0 :
F_7 ( L_11 ) ;
return 0 ;
case - V_14 :
F_12 ( V_58 L_5
L_12 ,
V_2 -> V_5 . V_12 , V_47 , V_2 -> V_7 -> V_12 ) ;
F_7 ( L_3 , V_11 ) ;
return V_11 ;
}
}
static void F_22 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
F_4 ( L_13 ,
V_5 -> V_12 , V_5 -> V_48 ,
F_20 ( V_5 -> V_49 [ 0 ] . V_18 ) , V_5 -> V_50 [ 0 ] ,
F_20 ( V_5 -> V_49 [ 1 ] . V_18 ) , V_5 -> V_50 [ 1 ] ,
F_20 ( V_5 -> V_49 [ 2 ] . V_18 ) , V_5 -> V_50 [ 2 ] ) ;
F_4 ( L_9 ,
V_5 -> V_47 [ 0 ] , V_5 -> V_47 [ 1 ] , V_5 -> V_47 [ 2 ] ) ;
if ( strcmp ( V_5 -> V_12 , V_2 -> V_5 . V_12 ) != 0 )
F_12 ( V_35 L_5
L_14 ,
V_2 -> V_5 . V_12 , V_5 -> V_12 ) ;
V_2 -> V_5 = * V_5 ;
#ifdef F_23
F_24 ( V_2 -> V_59 ) ;
#endif
}
static int F_25 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
struct V_4 V_5 ;
int V_11 ;
F_2 ( L_15 ) ;
F_26 ( V_2 -> V_36 , == , 0 ) ;
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
#ifdef F_23
V_2 -> V_59 = F_27 ( V_2 -> V_7 -> V_59 ,
& V_60 , V_2 ,
true ) ;
#endif
if ( V_2 -> V_36 ) {
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
struct V_1 * V_61 ;
V_2 -> V_62 = F_29 () +
V_63 ;
F_30 ( & V_64 ) ;
if ( ! F_31 ( & V_65 ) ) {
V_61 = F_32 ( V_65 . V_66 ,
struct V_1 , V_44 ) ;
if ( V_2 -> V_62 <= V_61 -> V_62 )
V_2 -> V_62 = V_61 -> V_62 + 1 ;
} else {
F_33 ( V_67 ,
& V_68 ,
V_63 * V_69 ) ;
}
F_34 ( & V_2 -> V_44 , & V_65 ) ;
F_35 ( & V_64 ) ;
}
struct V_1 * F_36 ( struct V_6 * V_7 ,
struct V_3 * V_3 ,
const char * V_12 ,
T_3 V_37 )
{
struct V_1 * V_2 ;
int V_11 ;
F_2 ( L_18 ,
V_7 -> V_12 , F_37 ( V_3 ) ,
( int ) V_37 , ( int ) V_37 , V_12 , V_37 ) ;
if ( V_37 >= sizeof( V_2 -> V_5 . V_12 ) ) {
F_7 ( L_19 ) ;
return F_38 ( - V_70 ) ;
}
F_3 ( & V_7 -> V_13 ) ;
F_30 ( & V_7 -> V_71 ) ;
F_39 (vl, &cell->vl_list, link) {
if ( V_2 -> V_5 . V_12 [ V_37 ] != '\0' )
continue;
if ( memcmp ( V_2 -> V_5 . V_12 , V_12 , V_37 ) == 0 )
goto V_72;
}
F_35 ( & V_7 -> V_71 ) ;
V_2 = F_13 ( V_7 , V_12 , V_37 ) ;
if ( ! V_2 ) {
F_6 ( & V_7 -> V_13 ) ;
return F_38 ( - V_20 ) ;
}
F_40 ( V_7 ) ;
F_34 ( & V_2 -> V_42 , & V_7 -> V_73 ) ;
V_2 -> V_39 = V_74 ;
F_6 ( & V_7 -> V_13 ) ;
V_75:
V_11 = F_25 ( V_2 , V_3 ) ;
if ( V_11 < 0 )
goto V_76;
F_30 ( & V_2 -> V_46 ) ;
V_2 -> V_39 = V_77 ;
F_35 ( & V_2 -> V_46 ) ;
F_41 ( & V_2 -> V_45 ) ;
#ifdef F_23
F_24 ( V_2 -> V_59 ) ;
#endif
F_28 ( V_2 ) ;
goto V_78;
V_72:
F_4 ( L_20 ) ;
F_42 ( & V_2 -> V_41 ) ;
F_35 ( & V_7 -> V_71 ) ;
if ( ! F_31 ( & V_2 -> V_43 ) ) {
F_30 ( & V_79 ) ;
F_43 ( & V_2 -> V_43 ) ;
F_35 ( & V_79 ) ;
}
F_6 ( & V_7 -> V_13 ) ;
F_30 ( & V_2 -> V_46 ) ;
while ( V_2 -> V_39 != V_77 ) {
T_4 V_39 = V_2 -> V_39 ;
F_4 ( L_21 , V_39 ) ;
if ( V_39 == V_40 || V_39 == V_80 ) {
V_2 -> V_39 = V_74 ;
F_35 ( & V_2 -> V_46 ) ;
goto V_75;
}
F_4 ( L_22 ) ;
F_35 ( & V_2 -> V_46 ) ;
V_11 = F_44 ( V_2 -> V_45 ,
V_2 -> V_39 == V_40 ||
V_2 -> V_39 == V_77 ||
V_2 -> V_39 == V_80 ) ;
if ( V_11 < 0 )
goto error;
F_30 ( & V_2 -> V_46 ) ;
}
F_35 ( & V_2 -> V_46 ) ;
V_78:
F_7 ( L_7 , V_2 ) ;
return V_2 ;
V_76:
F_30 ( & V_2 -> V_46 ) ;
V_2 -> V_39 = V_40 ;
F_35 ( & V_2 -> V_46 ) ;
F_41 ( & V_2 -> V_45 ) ;
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
F_26 ( F_46 ( & V_2 -> V_41 ) , > , 0 ) ;
if ( F_47 ( ! F_48 ( & V_2 -> V_41 ) ) ) {
F_7 ( L_15 ) ;
return;
}
F_30 ( & V_79 ) ;
if ( F_46 ( & V_2 -> V_41 ) == 0 ) {
F_4 ( L_24 ) ;
F_49 ( & V_2 -> V_43 , & V_81 ) ;
V_2 -> V_82 = F_29 () ;
F_33 ( V_83 , & V_84 ,
V_85 * V_69 ) ;
if ( ! F_31 ( & V_2 -> V_44 ) ) {
F_30 ( & V_64 ) ;
F_43 ( & V_2 -> V_44 ) ;
F_35 ( & V_64 ) ;
}
}
F_35 ( & V_79 ) ;
F_7 ( L_25 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
F_2 ( L_26 , V_2 ) ;
#ifdef F_23
F_51 ( V_2 -> V_59 , 0 ) ;
#endif
F_52 ( V_2 -> V_7 ) ;
F_53 ( V_2 ) ;
}
static void F_54 ( struct V_86 * V_87 )
{
F_55 ( V_88 ) ;
struct V_1 * V_2 ;
unsigned long V_89 , V_90 ;
T_5 V_91 ;
F_2 ( L_15 ) ;
V_91 = F_29 () ;
F_30 ( & V_79 ) ;
while ( ! F_31 ( & V_81 ) ) {
V_2 = F_32 ( V_81 . V_92 ,
struct V_1 , V_43 ) ;
F_4 ( L_27 , V_2 ) ;
V_90 = V_2 -> V_82 + V_85 ;
if ( V_90 > V_91 ) {
V_89 = ( V_90 - V_91 ) * V_69 ;
F_4 ( L_28 , V_89 ) ;
F_56 ( V_83 , & V_84 , V_89 ) ;
break;
}
F_30 ( & V_2 -> V_7 -> V_71 ) ;
if ( F_46 ( & V_2 -> V_41 ) > 0 ) {
F_4 ( L_29 ) ;
F_43 ( & V_2 -> V_43 ) ;
} else {
F_4 ( L_30 ) ;
F_49 ( & V_2 -> V_43 , & V_88 ) ;
F_43 ( & V_2 -> V_42 ) ;
}
F_35 ( & V_2 -> V_7 -> V_71 ) ;
}
F_35 ( & V_79 ) ;
while ( ! F_31 ( & V_88 ) ) {
V_2 = F_32 ( V_88 . V_92 , struct V_1 , V_43 ) ;
F_57 ( & V_2 -> V_43 ) ;
F_50 ( V_2 ) ;
}
F_7 ( L_15 ) ;
}
int T_6 F_58 ( void )
{
V_67 = F_59 ( L_31 ,
V_93 , 0 ) ;
return V_67 ? 0 : - V_20 ;
}
void F_60 ( void )
{
V_85 = 0 ;
F_30 ( & V_64 ) ;
F_43 ( & V_65 ) ;
F_35 ( & V_64 ) ;
F_56 ( V_67 , & V_68 , 0 ) ;
F_61 ( V_67 ) ;
F_56 ( V_83 , & V_84 , 0 ) ;
}
static void F_62 ( struct V_86 * V_87 )
{
struct V_4 V_5 ;
struct V_1 * V_2 , * V_61 ;
T_5 V_91 ;
long V_94 ;
int V_11 ;
F_2 ( L_15 ) ;
V_91 = F_29 () ;
F_30 ( & V_64 ) ;
for (; ; ) {
if ( F_31 ( & V_65 ) ) {
F_35 ( & V_64 ) ;
F_7 ( L_32 ) ;
return;
}
V_2 = F_32 ( V_65 . V_92 ,
struct V_1 , V_44 ) ;
if ( F_46 ( & V_2 -> V_41 ) > 0 )
break;
F_43 ( & V_2 -> V_44 ) ;
}
V_94 = V_2 -> V_62 - V_91 ;
if ( V_94 > 0 ) {
F_33 ( V_67 ,
& V_68 , V_94 * V_69 ) ;
F_35 ( & V_64 ) ;
F_7 ( L_32 ) ;
return;
}
F_43 ( & V_2 -> V_44 ) ;
F_42 ( & V_2 -> V_41 ) ;
F_35 ( & V_64 ) ;
F_4 ( L_33 , V_2 -> V_5 . V_12 ) ;
V_2 -> V_39 = V_95 ;
V_2 -> V_34 = 0 ;
V_2 -> V_32 = 0 ;
V_11 = F_19 ( V_2 , NULL , & V_5 ) ;
F_30 ( & V_2 -> V_46 ) ;
switch ( V_11 ) {
case 0 :
F_22 ( V_2 , & V_5 ) ;
V_2 -> V_39 = V_77 ;
break;
case - V_14 :
V_2 -> V_39 = V_96 ;
break;
default:
V_2 -> V_39 = V_97 ;
break;
}
F_35 ( & V_2 -> V_46 ) ;
F_41 ( & V_2 -> V_45 ) ;
F_4 ( L_34 ) ;
V_2 -> V_62 = F_29 () +
V_63 ;
F_30 ( & V_64 ) ;
if ( ! F_31 ( & V_65 ) ) {
V_61 = F_32 ( V_65 . V_66 ,
struct V_1 , V_44 ) ;
if ( V_2 -> V_62 <= V_61 -> V_62 )
V_2 -> V_62 = V_61 -> V_62 + 1 ;
V_61 = F_32 ( V_65 . V_92 ,
struct V_1 , V_44 ) ;
V_94 = V_61 -> V_62 - V_91 ;
if ( V_94 < 0 )
V_94 = 0 ;
} else {
V_94 = V_63 ;
}
ASSERT ( F_31 ( & V_2 -> V_44 ) ) ;
F_34 ( & V_2 -> V_44 , & V_65 ) ;
F_4 ( L_35 , V_94 ) ;
F_33 ( V_67 ,
& V_68 , V_94 * V_69 ) ;
F_35 ( & V_64 ) ;
F_45 ( V_2 ) ;
}
