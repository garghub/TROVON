static int F_1 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 )
{
T_2 V_5 ;
int V_6 ;
#ifndef F_2
static T_2 V_7 ;
#endif
F_3 ( V_8 , V_2 , V_2 -> V_9 -> V_10 , V_11 , V_3 , V_4 ,
L_1 , V_12 , V_4 ) ;
while ( V_4 ) {
V_5 = * ( T_2 * ) V_3 ;
F_4 ( V_2 -> V_13 . V_14 , 0 ) ;
#ifndef F_2
if ( V_5 == V_7 ) {
F_4 ( V_2 -> V_13 . V_14 , 0 ) ;
} else {
for ( V_6 = 0 ; V_6 < 16 ; V_6 ++ ) {
if ( ( V_5 & 1 ) != ( V_7 & 1 ) )
F_4 ( V_2 -> V_13 . V_15 [ V_6 ] ,
V_5 & 1 ) ;
V_5 >>= 1 ;
V_7 >>= 1 ;
}
}
#else
for ( V_6 = 0 ; V_6 < 16 ; V_6 ++ ) {
F_4 ( V_2 -> V_13 . V_15 [ V_6 ] , V_5 & 1 ) ;
V_5 >>= 1 ;
}
#endif
F_4 ( V_2 -> V_13 . V_14 , 1 ) ;
#ifndef F_2
V_7 = * ( T_2 * ) V_3 ;
#endif
V_3 += 2 ;
V_4 -= 2 ;
}
return 0 ;
}
static void F_5 ( struct V_1 * V_2 ,
int V_16 , int V_17 , int V_18 , int V_19 )
{
F_6 ( V_20 , V_2 ,
L_2 , V_12 , V_16 , V_17 , V_18 , V_19 ) ;
F_7 ( V_2 , 0x2A , 0 , V_16 + 2 , 0 , V_18 + 2 ) ;
F_7 ( V_2 , 0x2B , 0 , V_17 + 1 , 0 , V_19 + 1 ) ;
F_7 ( V_2 , 0x2C ) ;
}
static void F_8 ( struct V_10 * V_21 )
{
}
static int F_9 ( struct V_10 * V_21 , void * V_5 )
{
struct V_22 * V_23 = F_10 ( V_21 , struct V_22 , V_21 ) ;
F_11 ( V_24 L_3 ,
V_23 -> V_25 , F_12 ( V_21 ) , V_23 -> V_26 / 1000 ,
V_23 -> V_27 , V_23 -> V_28 ) ;
return 0 ;
}
static void F_13 ( void )
{
F_11 ( V_24 L_4 ) ;
F_14 ( & V_29 , NULL , NULL , F_9 ) ;
}
static int F_15 ( struct V_10 * V_21 , void * V_5 )
{
struct V_30
* V_31 = F_10 ( V_21 , struct V_30 , V_21 ) ;
if ( strstr ( V_31 -> V_32 , L_5 ) )
F_11 ( V_24 L_6 ,
V_31 -> V_32 , V_31 -> V_33 ,
V_31 -> V_21 . V_34 ? L_7 : L_8 ) ;
return 0 ;
}
static void F_16 ( void )
{
F_11 ( V_24 L_9 ) ;
F_14 ( & V_35 , NULL , NULL , F_15 ) ;
}
static void F_17 ( struct V_36 * V_37 , unsigned V_38 )
{
struct V_10 * V_21 ;
char V_39 [ 32 ] ;
snprintf ( V_39 , sizeof( V_39 ) , L_10 , F_12 ( & V_37 -> V_21 ) , V_38 ) ;
V_21 = F_18 ( & V_29 , NULL , V_39 ) ;
if ( V_21 ) {
if ( V_40 )
F_11 ( V_24 L_11 , V_39 ) ;
F_19 ( V_21 ) ;
}
}
static int F_20 ( struct V_41 * V_23 )
{
struct V_36 * V_37 ;
V_37 = F_21 ( V_23 -> V_42 ) ;
if ( ! V_37 ) {
F_22 ( V_24 L_12 ,
V_23 -> V_42 ) ;
return - V_43 ;
}
F_17 ( V_37 , V_23 -> V_44 ) ;
V_22 = F_23 ( V_37 , V_23 ) ;
F_24 ( & V_37 -> V_21 ) ;
if ( ! V_22 ) {
F_22 ( V_24 L_13 ) ;
return - V_45 ;
}
return 0 ;
}
static int F_20 ( struct V_41 * V_23 )
{
return F_25 ( V_23 , 1 ) ;
}
static int T_3 F_26 ( void )
{
struct V_41 * V_23 = NULL ;
struct V_46 * V_47 ;
const struct V_48 * V_13 = NULL ;
char * V_49 , * V_50 , * V_51 ;
bool V_52 = false ;
int V_6 = 0 ;
long V_53 ;
int V_54 = 0 ;
F_27 ( L_14 V_24 L_15 ) ;
if ( V_32 == NULL ) {
#ifdef F_28
F_22 ( V_24 L_16 ) ;
return - V_43 ;
#else
return 0 ;
#endif
}
if ( V_55 > V_56 ) {
F_22 ( V_24
L_17 ,
V_56 ) ;
return - V_43 ;
}
while ( ( V_49 = F_29 ( & V_57 , L_18 ) ) ) {
if ( strchr ( V_49 , ':' ) == NULL ) {
F_22 ( V_24
L_19 ,
V_49 ) ;
return - V_43 ;
}
V_51 = V_49 ;
V_50 = F_29 ( & V_51 , L_20 ) ;
if ( V_50 == NULL || V_51 == NULL ) {
F_22 ( V_24
L_21 ,
V_49 ) ;
return - V_43 ;
}
V_54 = F_30 ( V_51 , 10 , & V_53 ) ;
if ( V_54 ) {
F_22 ( V_24
L_22 ,
V_50 , V_51 ) ;
return - V_43 ;
}
strcpy ( V_58 [ V_6 ] . V_32 , V_50 ) ;
V_58 [ V_6 ++ ] . V_13 = ( int ) V_53 ;
if ( V_6 == V_59 ) {
F_22 ( V_24
L_23 ,
V_59 ) ;
return - V_43 ;
}
}
if ( V_58 [ 0 ] . V_32 [ 0 ] )
V_13 = V_58 ;
if ( V_40 > 2 )
F_13 () ;
if ( V_40 > 2 )
F_16 () ;
F_27 ( V_24 L_24 , V_32 , V_60 , V_38 ) ;
if ( V_61 > 0 && V_61 < 4 ) {
V_61 = ( 4 - V_61 ) * 90 ;
F_31 ( L_25 ,
V_61 ) ;
}
if ( V_61 != 0 && V_61 != 90 && V_61 != 180 && V_61 != 270 ) {
F_31 ( L_26 ,
V_61 ) ;
V_61 = 0 ;
}
if ( strncmp ( V_32 , L_27 , 32 ) == 0 ) {
F_11 ( V_24 L_28 ) ;
for ( V_6 = 0 ; V_6 < F_32 ( V_62 ) ; V_6 ++ )
F_11 ( V_24 L_29 , V_62 [ V_6 ] . V_32 ) ;
return - V_63 ;
}
if ( V_64 ) {
V_6 = F_32 ( V_62 ) - 1 ;
V_62 [ V_6 ] . V_32 = V_32 ;
if ( V_65 == 0 ) {
V_62 [ V_6 ] . V_31 -> V_32 = V_32 ;
V_62 [ V_6 ] . V_23 = NULL ;
} else {
strncpy ( V_62 [ V_6 ] . V_23 -> V_25 , V_32 , V_66 ) ;
V_62 [ V_6 ] . V_31 = NULL ;
}
}
for ( V_6 = 0 ; V_6 < F_32 ( V_62 ) ; V_6 ++ ) {
if ( strncmp ( V_32 , V_62 [ V_6 ] . V_32 , 32 ) == 0 ) {
if ( V_62 [ V_6 ] . V_23 ) {
V_23 = V_62 [ V_6 ] . V_23 ;
V_23 -> V_44 = V_38 ;
V_23 -> V_42 = V_60 ;
if ( V_65 )
V_23 -> V_26 = V_65 ;
if ( V_28 != - 1 )
V_23 -> V_28 = V_28 ;
V_47 = ( void * ) V_23 -> V_34 ;
} else if ( V_62 [ V_6 ] . V_31 ) {
V_67 = V_62 [ V_6 ] . V_31 ;
V_47 = V_67 -> V_21 . V_34 ;
} else {
F_22 ( V_24 L_30 ) ;
return - V_43 ;
}
V_47 -> V_61 = V_61 ;
if ( V_68 == 0 )
V_47 -> V_68 = false ;
else if ( V_68 == 1 )
V_47 -> V_68 = true ;
if ( V_69 )
V_47 -> V_69 = V_69 ;
if ( gamma )
V_47 -> gamma = gamma ;
V_47 -> V_70 . V_71 = V_71 ;
if ( V_72 )
V_47 -> V_72 = V_72 ;
if ( V_73 )
V_47 -> V_73 = V_73 ;
if ( V_55 )
V_47 -> V_70 . V_74 = V_75 ;
if ( V_13 )
V_47 -> V_57 = V_13 ;
if ( V_64 ) {
V_47 -> V_70 . V_76 = V_76 ;
V_47 -> V_70 . V_77 = V_77 ;
V_47 -> V_70 . V_78 = V_78 ;
V_47 -> V_70 . V_79 = 1 ;
}
if ( V_62 [ V_6 ] . V_23 ) {
V_54 = F_20 ( V_23 ) ;
if ( V_54 ) {
F_22 ( V_24
L_31 ) ;
return V_54 ;
}
} else {
V_54 = F_33 ( V_67 ) ;
if ( V_54 < 0 ) {
F_22 ( V_24
L_32 ,
V_54 ) ;
return V_54 ;
}
}
V_52 = true ;
break;
}
}
if ( ! V_52 ) {
F_22 ( V_24 L_33 , V_32 ) ;
return - V_43 ;
}
if ( V_40 && V_47 && V_47 -> V_57 ) {
V_13 = V_47 -> V_57 ;
F_11 ( V_24 L_34 , V_32 ) ;
V_52 = false ;
while ( V_40 && V_13 -> V_32 [ 0 ] ) {
F_11 ( V_24 L_35 ,
V_13 -> V_32 , V_13 -> V_13 ) ;
V_13 ++ ;
V_52 = true ;
}
if ( ! V_52 )
F_11 ( V_24 L_36 ) ;
}
if ( V_22 && ( V_40 > 1 ) )
F_13 () ;
if ( V_67 && ( V_40 > 1 ) )
F_16 () ;
return 0 ;
}
static void T_4 F_34 ( void )
{
F_27 ( V_24 L_37 ) ;
if ( V_22 ) {
F_19 ( & V_22 -> V_21 ) ;
F_35 ( V_22 ) ;
}
if ( V_67 )
F_36 ( V_67 ) ;
}
