static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_7 * V_8 ;
int V_9 ;
unsigned long V_10 ;
if ( F_3 ( V_2 -> V_11 > V_12 ) ) {
F_4 ( V_2 ) ;
return V_13 ;
}
V_9 = V_14 ;
V_14 = ( V_14 + 1 ) % V_15 ;
V_8 = V_16 + V_9 ;
V_8 -> V_17 = V_2 -> V_11 ;
V_8 -> V_18 = V_6 -> V_18 ;
F_5 ( V_2 , F_6 ( V_8 -> V_19 ) ) ;
F_4 ( V_2 ) ;
F_7 ( V_20 ,
V_21 + ( V_9 * sizeof( struct V_7 ) ) ) ;
F_8 ( V_10 ) ;
V_6 -> V_22 ++ ;
if ( V_6 -> V_22 == V_23 )
F_9 ( V_4 ) ;
F_10 ( V_10 ) ;
return V_13 ;
}
static int F_11 ( struct V_3 * V_4 , int V_24 , int V_25 )
{
while ( V_24 < V_25 ) {
struct V_26 * V_8 ;
struct V_1 * V_2 ;
void * V_27 ;
T_1 V_28 ;
V_28 = F_12 ( V_29 ) ;
if ( V_28 == 0 )
return 0 ;
V_8 = V_30 +
( ( V_28 - V_31 ) / sizeof( struct V_26 ) ) ;
V_27 = F_6 ( V_8 -> V_19 ) ;
if ( V_8 -> V_17 < 4 || V_8 -> V_17 > V_12 ) {
F_13 ( V_32 L_1 ,
V_8 -> V_17 ) ;
goto V_33;
}
if ( V_8 -> V_18 < 0 || V_8 -> V_18 >= V_34 ) {
F_13 ( V_32 L_2 ,
V_8 -> V_18 ) ;
goto V_33;
}
V_8 -> V_17 -= 4 ;
if ( F_3 ( ! F_14 ( V_35 [ V_8 -> V_18 ] ) ) )
goto V_33;
V_2 = F_15 ( V_4 , V_8 -> V_17 ) ;
if ( F_16 ( V_2 != NULL ) ) {
F_17 ( V_2 , V_27 , V_8 -> V_17 ) ;
F_18 ( V_2 , V_8 -> V_17 ) ;
V_2 -> V_36 = F_19 ( V_2 , V_35 [ V_8 -> V_18 ] ) ;
F_20 ( V_2 ) ;
}
V_33:
F_7 ( V_37 , V_28 ) ;
V_24 ++ ;
}
return V_24 ;
}
static int F_21 ( struct V_38 * V_39 , int V_25 )
{
struct V_5 * V_6 = F_22 ( V_39 , struct V_5 , V_39 ) ;
struct V_3 * V_4 = V_6 -> V_4 ;
int V_40 ;
V_40 = 0 ;
do {
F_7 ( V_41 , 0x00ff ) ;
V_40 = F_11 ( V_4 , V_40 , V_25 ) ;
if ( V_40 >= V_25 )
break;
} while ( F_12 ( V_41 ) & 0x00ff );
F_23 ( V_39 ) ;
F_7 ( V_42 , 0x00ff ) ;
return V_40 ;
}
static void F_24 ( void )
{
int V_18 ;
T_1 V_43 ;
V_43 = 0 ;
while ( 1 ) {
struct V_5 * V_6 ;
T_1 V_8 ;
int V_9 ;
V_8 = F_12 ( V_44 ) ;
if ( V_8 == 0 )
break;
V_9 = ( V_8 - V_21 ) / sizeof( struct V_7 ) ;
V_18 = V_16 [ V_9 ] . V_18 ;
if ( V_18 < 0 || V_18 >= V_34 ) {
F_13 ( V_32 L_3
L_4 ,
V_18 , ( unsigned int ) V_8 , V_9 ) ;
continue;
}
V_6 = F_2 ( V_35 [ V_18 ] ) ;
if ( V_6 -> V_22 == V_23 )
V_43 |= 1 << V_18 ;
V_6 -> V_22 -- ;
}
for ( V_18 = 0 ; V_43 != 0 ; V_18 ++ ) {
if ( V_43 & ( 1 << V_18 ) ) {
F_25 ( V_35 [ V_18 ] ) ;
V_43 &= ~ ( 1 << V_18 ) ;
}
}
}
static T_2 F_26 ( int V_45 , void * V_46 )
{
T_1 V_47 ;
V_47 = F_12 ( V_48 ) ;
if ( V_47 == 0 )
return V_49 ;
if ( V_47 & 0x00ff ) {
struct V_3 * V_4 = V_35 [ 0 ] ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_27 ( V_50 , 0x00ff ) ;
if ( F_16 ( F_28 ( & V_6 -> V_39 ) ) ) {
F_29 ( & V_6 -> V_39 ) ;
} else {
F_13 ( V_51 L_5 ) ;
}
}
if ( V_47 & 0xff00 ) {
F_27 ( V_41 , 0xff00 ) ;
F_24 () ;
}
return V_52 ;
}
static void F_30 ( struct V_3 * V_4 )
{
F_31 ( V_53 ) ;
F_26 ( V_53 , V_4 ) ;
F_32 ( V_53 ) ;
}
static int F_33 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_33 ;
F_34 ( & V_6 -> V_39 ) ;
if ( ! V_54 ++ ) {
V_33 = F_35 ( V_53 , F_26 ,
V_55 , L_6 , V_35 ) ;
if ( V_33 ) {
V_54 -- ;
F_36 ( & V_6 -> V_39 ) ;
return V_33 ;
}
F_7 ( V_42 , 0xffff ) ;
}
F_37 ( V_6 -> V_18 , 1 ) ;
F_38 ( V_4 ) ;
return 0 ;
}
static int F_39 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_9 ( V_4 ) ;
F_36 ( & V_6 -> V_39 ) ;
F_37 ( V_6 -> V_18 , 0 ) ;
if ( ! -- V_54 ) {
F_7 ( V_50 , 0xffff ) ;
F_40 ( V_53 , V_35 ) ;
}
return 0 ;
}
static struct V_56 * F_41 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_42 ( V_6 -> V_18 , & ( V_4 -> V_57 ) ) ;
return & ( V_4 -> V_57 ) ;
}
struct V_3 * F_43 ( int V_18 , int V_58 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
V_4 = F_44 ( V_58 ) ;
if ( V_4 == NULL )
return NULL ;
V_4 -> V_59 = & V_60 ;
V_4 -> V_61 |= V_62 | V_63 ;
V_6 = F_2 ( V_4 ) ;
V_6 -> V_4 = V_4 ;
F_45 ( V_4 , & V_6 -> V_39 , F_21 , 64 ) ;
V_6 -> V_18 = V_18 ;
V_6 -> V_22 = 0 ;
return V_4 ;
}
int F_46 ( int V_64 , struct V_3 * * V_65 ,
void (* F_47)( int V_66 , int V_67 ) )
{
int V_68 ;
int V_33 ;
F_48 ( V_69 > 192 || V_15 > 192 ) ;
F_13 ( V_70 L_7 , V_71 ) ;
V_34 = V_64 ;
V_35 = V_65 ;
F_37 = F_47 ;
for ( V_68 = 0 ; V_68 < V_69 ; V_68 ++ ) {
void * V_27 ;
V_27 = ( void * ) F_49 ( V_72 ) ;
if ( V_27 == NULL ) {
V_33 = - V_73 ;
while ( -- V_68 >= 0 )
F_50 ( ( unsigned long ) F_6 ( V_30 [ V_68 ] . V_19 ) ) ;
goto V_74;
}
V_30 [ V_68 ] . V_19 = F_51 ( V_27 ) ;
V_30 [ V_68 ] . V_75 = V_12 ;
}
for ( V_68 = 0 ; V_68 < V_15 ; V_68 ++ ) {
void * V_27 ;
V_27 = ( void * ) F_49 ( V_72 ) ;
if ( V_27 == NULL ) {
V_33 = - V_73 ;
while ( -- V_68 >= 0 )
F_50 ( ( unsigned long ) F_6 ( V_16 [ V_68 ] . V_19 ) ) ;
goto V_76;
}
V_16 [ V_68 ] . V_19 = F_51 ( V_27 ) ;
}
F_7 ( V_77 , 0x44000000 ) ;
F_7 ( V_78 , 0x00000000 ) ;
F_7 ( V_79 , 0x00000000 ) ;
F_7 ( V_80 , 0x40000400 ) ;
F_7 ( V_81 , 0x00000000 ) ;
F_7 ( V_82 , 0x00000000 ) ;
for ( V_68 = 0 ; V_68 < V_69 ; V_68 ++ ) {
F_7 ( V_37 ,
V_31 + ( V_68 * sizeof( struct V_26 ) ) ) ;
}
F_52 ( 0 , & V_83 ) ;
F_53 ( 0 , 0xff ) ;
F_7 ( V_84 , 0x44000800 ) ;
F_7 ( V_85 , 0x00000000 ) ;
F_7 ( V_86 , 0x00000000 ) ;
F_7 ( V_87 , 0x40000c00 ) ;
F_7 ( V_88 , 0x00000000 ) ;
F_7 ( V_89 , 0x00000000 ) ;
F_52 ( 1 , & V_90 ) ;
F_53 ( 1 , 0xff ) ;
for ( V_68 = 0 ; V_68 < V_34 ; V_68 ++ ) {
V_33 = F_54 ( V_35 [ V_68 ] ) ;
if ( V_33 ) {
while ( -- V_68 >= 0 )
F_55 ( V_35 [ V_68 ] ) ;
goto V_91;
}
}
for ( V_68 = 0 ; V_68 < V_34 ; V_68 ++ ) {
F_13 ( V_70 L_8
L_9 , V_35 [ V_68 ] -> V_92 , V_68 ,
V_35 [ V_68 ] -> V_93 [ 0 ] , V_35 [ V_68 ] -> V_93 [ 1 ] ,
V_35 [ V_68 ] -> V_93 [ 2 ] , V_35 [ V_68 ] -> V_93 [ 3 ] ,
V_35 [ V_68 ] -> V_93 [ 4 ] , V_35 [ V_68 ] -> V_93 [ 5 ] ) ;
}
return 0 ;
V_91:
for ( V_68 = 0 ; V_68 < V_15 ; V_68 ++ )
F_50 ( ( unsigned long ) F_6 ( V_16 [ V_68 ] . V_19 ) ) ;
V_76:
for ( V_68 = 0 ; V_68 < V_69 ; V_68 ++ )
F_50 ( ( unsigned long ) F_6 ( V_30 [ V_68 ] . V_19 ) ) ;
V_74:
return V_33 ;
}
void F_56 ( void )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_34 ; V_68 ++ )
F_55 ( V_35 [ V_68 ] ) ;
F_57 ( 1 , 0xff ) ;
F_57 ( 0 , 0xff ) ;
F_58 ( 0x3 ) ;
for ( V_68 = 0 ; V_68 < V_15 ; V_68 ++ )
F_50 ( ( unsigned long ) F_6 ( V_16 [ V_68 ] . V_19 ) ) ;
for ( V_68 = 0 ; V_68 < V_69 ; V_68 ++ )
F_50 ( ( unsigned long ) F_6 ( V_30 [ V_68 ] . V_19 ) ) ;
}
