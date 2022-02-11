static void F_1 ( char * V_1 , ... )
{
int V_2 ;
unsigned long V_3 ;
T_1 args ;
static char V_4 [ 256 ] ;
F_2 ( & V_5 , V_3 ) ;
va_start ( args , V_1 ) ;
V_2 = F_3 ( V_4 , sizeof( V_4 ) - 1 , V_1 , args ) ;
va_end ( args ) ;
V_4 [ V_2 ++ ] = '\r' ;
F_4 ( V_4 , V_2 ) ;
F_5 ( & V_5 , V_3 ) ;
}
static void F_6 ( struct V_6 * V_7 , T_2 V_8 )
{
struct V_9 * V_10 = & V_7 -> V_11 ;
memset ( V_7 , 0 , sizeof( struct V_6 ) ) ;
V_10 -> V_3 = V_12 | V_13 |
V_14 ;
V_10 -> V_15 = V_16 ;
V_10 -> V_17 = V_18 | V_19 ;
V_10 -> V_20 = F_7 () ;
V_10 -> V_21 = V_8 ;
V_10 -> V_22 = sizeof( struct V_6 ) ;
V_10 -> V_23 = F_8 ( V_8 ) ;
V_10 -> V_24 = F_9 ( V_8 ) ;
}
static int F_10 ( T_3 V_25 , char * V_4 , int V_26 )
{
struct V_27 * V_28 ;
int V_29 = 0 ;
unsigned long V_3 ;
if ( V_25 >= V_30 )
return - V_31 ;
if ( V_26 == 0 )
return 0 ;
V_28 = & V_27 [ V_25 ] ;
F_2 ( & V_32 , V_3 ) ;
if ( V_28 -> V_33 == 0 )
goto V_34;
V_29 = V_28 -> V_33 - V_28 -> V_35 ;
if ( V_29 > V_26 )
V_29 = V_26 ;
memcpy ( V_4 , & V_28 -> V_36 [ V_28 -> V_35 ] , V_29 ) ;
V_28 -> V_35 += V_29 ;
if ( V_28 -> V_35 == V_28 -> V_33 ) {
V_28 -> V_35 = 0 ;
V_28 -> V_33 = 0 ;
}
V_34:
F_5 ( & V_32 , V_3 ) ;
return V_29 ;
}
static int F_11 ( T_3 V_25 , const char * V_4 , int V_26 )
{
struct V_6 * V_7 ;
struct V_27 * V_28 ;
T_4 V_37 ;
unsigned long V_3 ;
int V_38 = 0 ;
if ( V_25 >= V_30 )
return - V_31 ;
V_28 = & V_27 [ V_25 ] ;
F_2 ( & V_32 , V_3 ) ;
if ( F_12 ( V_28 ) && ! F_13 ( V_28 -> V_8 ) ) {
F_4 ( V_4 , V_26 ) ;
V_38 = V_26 ;
goto V_34;
}
V_7 = F_14 ( V_18 ) ;
if ( V_7 == NULL ) {
F_1 ( L_1 ) ;
goto V_34;
}
while ( ( V_26 > 0 ) && ( ( V_28 -> V_39 - V_28 -> V_40 ) < V_41 ) ) {
int V_42 ;
V_42 = ( V_26 > V_43 ) ? V_43 : V_26 ;
if ( F_12 ( V_28 ) )
F_4 ( V_4 , V_42 ) ;
F_6 ( V_7 , V_28 -> V_8 ) ;
V_7 -> V_42 = V_42 ;
V_7 -> V_11 . V_44 = V_28 -> V_39 ++ ;
V_7 -> V_11 . V_22 =
F_15 ( struct V_6 , V_45 ) + V_42 ;
memcpy ( V_7 -> V_45 , V_4 , V_42 ) ;
V_37 = F_16 ( & V_7 -> V_11 ) ;
if ( V_37 )
F_1 ( L_2 ,
( int ) V_37 ) ;
V_38 += V_42 ;
V_26 -= V_42 ;
V_4 += V_42 ;
}
F_17 ( V_18 , V_7 ) ;
V_34:
F_5 ( & V_32 , V_3 ) ;
return V_38 ;
}
static int T_5 F_18 ( struct V_46 * V_47 ,
const struct V_48 * V_49 )
{
struct V_50 * V_51 ;
struct V_27 * V_28 ;
if ( ! V_47 || ! V_49 )
return - V_52 ;
if ( V_47 -> V_53 >= V_30 )
return - V_54 ;
V_28 = & V_27 [ V_47 -> V_53 ] ;
V_51 = F_19 ( V_47 -> V_53 , V_47 -> V_55 , & V_56 ,
V_43 ) ;
if ( F_20 ( V_51 ) )
return F_21 ( V_51 ) ;
V_28 -> V_51 = V_51 ;
F_22 ( & V_47 -> V_57 , V_28 ) ;
return 0 ;
}
static int T_6 F_23 ( struct V_46 * V_47 )
{
struct V_27 * V_28 = F_24 ( & V_47 -> V_57 ) ;
struct V_50 * V_51 = V_28 -> V_51 ;
return F_25 ( V_51 ) ;
}
static void F_26 ( struct V_9 * V_11 )
{
unsigned long V_3 ;
struct V_6 * V_58 = (struct V_6 * ) V_11 ;
T_7 V_59 = V_58 -> V_60 ;
struct V_27 * V_28 ;
int V_61 = 0 ;
if ( F_27 ( V_11 ) ) {
if ( V_59 >= V_30 )
return;
F_2 ( & V_32 , V_3 ) ;
V_28 = & V_27 [ V_59 ] ;
if ( V_11 -> V_62 == V_63 ) {
V_28 -> V_39 = V_28 -> V_40 = 0 ;
V_28 -> V_8 = V_11 -> V_21 ;
}
F_5 ( & V_32 , V_3 ) ;
if ( V_11 -> V_62 != V_63 )
F_28 ( V_64
L_3 ,
V_11 -> V_62 ) ;
if ( V_11 -> V_44 != 0 ) {
T_8 * V_65 = ( T_8 * ) V_11 -> V_44 ;
F_29 ( V_65 , 1 ) ;
} else
F_28 ( V_64
L_4 ) ;
return;
}
if ( ! F_30 ( V_11 ) ) {
F_28 ( V_64 L_5 ) ;
return;
}
F_2 ( & V_32 , V_3 ) ;
if ( V_59 >= V_30 ) {
V_11 -> V_62 = V_66 ;
V_58 -> V_67 = V_68 ;
V_61 = 1 ;
} else {
V_28 = & V_27 [ V_59 ] ;
if ( ( V_28 -> V_8 != V_69 ) &&
( V_28 -> V_8 != V_11 -> V_20 ) ) {
V_11 -> V_62 = V_66 ;
V_58 -> V_67 = V_68 ;
V_61 = 2 ;
} else {
V_28 -> V_8 = V_11 -> V_20 ;
V_11 -> V_62 = V_63 ;
V_58 -> V_67 = V_70 ;
V_28 -> V_39 = V_28 -> V_40 = 0 ;
}
}
F_5 ( & V_32 , V_3 ) ;
if ( V_61 == 1 )
F_28 ( V_64 L_6 ) ;
else if ( V_61 == 2 )
F_28 ( V_64 L_7
L_8 ) ;
F_31 ( V_11 ) ;
}
static void F_32 ( struct V_9 * V_11 )
{
unsigned long V_3 ;
struct V_6 * V_58 = (struct V_6 * ) V_11 ;
T_7 V_59 = V_58 -> V_60 ;
if ( ! F_33 ( V_11 ) ) {
F_28 ( V_64
L_9 ) ;
return;
}
if ( V_59 >= V_30 ) {
F_28 ( V_64
L_10 ) ;
return;
}
F_2 ( & V_32 , V_3 ) ;
if ( V_27 [ V_59 ] . V_8 == V_11 -> V_20 )
V_27 [ V_59 ] . V_8 = V_69 ;
F_5 ( & V_32 , V_3 ) ;
}
static void F_34 ( struct V_9 * V_11 )
{
unsigned long V_3 ;
struct V_6 * V_58 = (struct V_6 * ) V_11 ;
struct V_27 * V_28 ;
int V_29 ;
T_7 V_59 = V_58 -> V_60 ;
if ( V_59 >= V_30 ) {
F_28 ( V_64 L_11 ,
V_59 ) ;
return;
}
if ( V_58 -> V_42 == 0 )
return;
V_28 = & V_27 [ V_59 ] ;
if ( V_28 -> V_8 != V_11 -> V_20 )
return;
F_2 ( & V_32 , V_3 ) ;
V_29 = V_71 - V_28 -> V_33 ;
if ( V_29 > V_58 -> V_42 )
V_29 = V_58 -> V_42 ;
if ( V_29 > 0 ) {
memcpy ( & V_28 -> V_36 [ V_28 -> V_33 ] , V_58 -> V_45 , V_29 ) ;
V_28 -> V_33 += V_29 ;
}
F_5 ( & V_32 , V_3 ) ;
if ( V_29 == 0 )
F_28 ( V_64 L_12 ) ;
}
static void F_35 ( struct V_9 * V_11 )
{
struct V_6 * V_58 = (struct V_6 * ) V_11 ;
unsigned long V_3 ;
T_7 V_59 = V_58 -> V_60 ;
if ( V_59 >= V_30 ) {
F_28 ( V_64 L_13 ) ;
return;
}
F_2 ( & V_32 , V_3 ) ;
V_27 [ V_59 ] . V_40 = V_11 -> V_44 ;
F_5 ( & V_32 , V_3 ) ;
}
static void F_36 ( struct V_9 * V_11 )
{
struct V_6 * V_58 = (struct V_6 * ) V_11 ;
if ( V_58 -> V_45 [ 0 ] == 0x01 )
F_28 ( V_72 L_14 ,
V_58 -> V_45 [ 1 ] , V_58 -> V_45 [ 2 ] ,
V_58 -> V_45 [ 3 ] , V_58 -> V_45 [ 4 ] ) ;
else
F_28 ( V_64 L_15 ) ;
}
static void F_37 ( struct V_9 * V_11 )
{
int V_73 ;
if ( V_11 == NULL )
return;
V_73 = V_11 -> V_17 & V_74 ;
switch ( V_73 ) {
case V_75 :
F_26 ( V_11 ) ;
break;
case V_76 :
F_32 ( V_11 ) ;
break;
case V_19 :
F_34 ( V_11 ) ;
break;
case V_77 :
F_35 ( V_11 ) ;
break;
case V_78 :
F_36 ( V_11 ) ;
break;
default:
if ( F_33 ( V_11 ) && F_30 ( V_11 ) ) {
V_11 -> V_62 = V_79 ;
F_31 ( V_11 ) ;
}
}
}
static int T_9 F_38 ( T_2 V_80 , void * V_81 )
{
return F_39 ( V_80 ,
V_16 ,
V_18 | V_75 ,
V_82 , V_83 ,
F_8 ( V_80 ) ,
F_9 ( V_80 ) ,
( V_84 ) ( unsigned long ) V_81 , V_85 << 16 ,
0 , 0 , 0 , 0 ) ;
}
static int T_9 F_40 ( void )
{
T_8 V_86 ;
int V_87 ;
if ( ! F_41 ( V_88 ) )
return - V_89 ;
V_87 = F_42 ( F_43 () ,
V_18 , V_41 + 2 ) ;
if ( V_87 )
F_28 ( V_64 L_16 , V_87 ) ;
if ( V_90 == V_69 )
F_44 () ;
if ( ( V_90 != V_69 ) &&
( V_90 != F_43 () ) ) {
F_28 ( V_72 L_17 ,
V_90 ) ;
V_87 = F_42 ( V_90 , V_18 ,
V_41 + 2 ) ;
if ( V_87 )
F_28 ( V_64
L_18 ,
V_90 , V_87 ) ;
}
if ( F_45 ( V_18 , F_37 ) < 0 )
F_28 ( V_64
L_19 ) ;
F_29 ( & V_86 , 0 ) ;
if ( ( F_13 ( V_90 ) ) &&
( F_38 ( V_90 , & V_86 ) == 0 ) ) {
F_28 ( V_72 L_20 , V_90 ) ;
while ( F_46 ( & V_86 ) == 0 )
F_47 () ;
F_29 ( & V_86 , 0 ) ;
}
if ( ( ! F_13 ( V_27 [ 0 ] . V_8 ) ) &&
( F_13 ( F_43 () ) ) &&
( F_38 ( F_43 () , & V_86 ) == 0 ) ) {
F_28 ( V_72 L_21 ) ;
while ( F_46 ( & V_86 ) == 0 )
F_47 () ;
}
V_87 = F_48 ( & V_91 ) ;
return V_87 ;
}
static void T_10 F_49 ( void )
{
F_50 ( & V_91 ) ;
}
static int T_9 F_51 ( void )
{
struct V_92 * V_93 ;
int V_94 = 0 ;
for ( V_93 = F_52 ( NULL , L_22 ) ; V_93 != NULL ;
V_93 = F_52 ( V_93 , L_22 ) ) {
const T_3 * V_25 ;
if ( ( V_94 >= V_95 ) ||
( V_94 >= V_30 ) ) {
F_53 ( V_93 ) ;
break;
}
V_25 = F_54 ( V_93 , L_23 , NULL ) ;
if ( ! V_25 )
continue;
if ( ! F_55 ( V_93 , L_24 ) )
continue;
if ( V_94 == 0 )
F_56 ( L_25 , 0 , NULL ) ;
F_57 ( * V_25 , V_94 , & V_56 ) ;
++ V_94 ;
}
return V_94 ;
}
