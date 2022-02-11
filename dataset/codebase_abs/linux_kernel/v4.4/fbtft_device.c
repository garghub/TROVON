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
F_6 ( V_2 , 0x2A , 0 , V_16 + 2 , 0 , V_18 + 2 ) ;
F_6 ( V_2 , 0x2B , 0 , V_17 + 1 , 0 , V_19 + 1 ) ;
F_6 ( V_2 , 0x2C ) ;
}
static void F_7 ( struct V_10 * V_20 )
{
}
static int F_8 ( struct V_10 * V_20 , void * V_5 )
{
struct V_21 * V_22 = F_9 ( V_20 , struct V_21 , V_20 ) ;
F_10 ( V_20 , L_2 , V_22 -> V_23 ,
F_11 ( V_20 ) , V_22 -> V_24 / 1000 , V_22 -> V_25 ,
V_22 -> V_26 ) ;
return 0 ;
}
static void F_12 ( void )
{
F_13 ( L_3 ) ;
F_14 ( & V_27 , NULL , NULL , F_8 ) ;
}
static int F_15 ( struct V_10 * V_20 , void * V_5 )
{
struct V_28
* V_29 = F_9 ( V_20 , struct V_28 , V_20 ) ;
if ( strstr ( V_29 -> V_30 , L_4 ) )
F_10 ( V_20 , L_5 , V_29 -> V_30 , V_29 -> V_31 ,
V_29 -> V_20 . V_32 ? L_6 : L_7 ) ;
return 0 ;
}
static void F_16 ( void )
{
F_13 ( L_8 ) ;
F_14 ( & V_33 , NULL , NULL , F_15 ) ;
}
static void F_17 ( struct V_34 * V_35 , unsigned V_36 )
{
struct V_10 * V_20 ;
char V_37 [ 32 ] ;
snprintf ( V_37 , sizeof( V_37 ) , L_9 , F_11 ( & V_35 -> V_20 ) , V_36 ) ;
V_20 = F_18 ( & V_27 , NULL , V_37 ) ;
if ( V_20 ) {
if ( V_38 )
F_10 ( V_20 , L_10 , V_37 ) ;
F_19 ( V_20 ) ;
}
}
static int F_20 ( struct V_39 * V_22 )
{
struct V_34 * V_35 ;
V_35 = F_21 ( V_22 -> V_40 ) ;
if ( ! V_35 ) {
F_22 ( L_11 ,
V_22 -> V_40 ) ;
return - V_41 ;
}
F_17 ( V_35 , V_22 -> V_42 ) ;
V_21 = F_23 ( V_35 , V_22 ) ;
F_24 ( & V_35 -> V_20 ) ;
if ( ! V_21 ) {
F_25 ( & V_35 -> V_20 , L_12 ) ;
return - V_43 ;
}
return 0 ;
}
static int F_20 ( struct V_39 * V_22 )
{
return F_26 ( V_22 , 1 ) ;
}
static int T_3 F_27 ( void )
{
struct V_39 * V_22 = NULL ;
struct V_44 * V_45 ;
const struct V_46 * V_13 = NULL ;
char * V_47 , * V_48 , * V_49 ;
bool V_50 = false ;
int V_6 = 0 ;
long V_51 ;
int V_52 = 0 ;
if ( V_30 == NULL ) {
#ifdef F_28
F_22 ( L_13 ) ;
return - V_41 ;
#else
return 0 ;
#endif
}
if ( V_53 > V_54 ) {
F_22 ( L_14 ,
V_54 ) ;
return - V_41 ;
}
while ( ( V_47 = F_29 ( & V_55 , L_15 ) ) ) {
if ( strchr ( V_47 , ':' ) == NULL ) {
F_22 ( L_16 ,
V_47 ) ;
return - V_41 ;
}
V_49 = V_47 ;
V_48 = F_29 ( & V_49 , L_17 ) ;
if ( V_48 == NULL || V_49 == NULL ) {
F_22 ( L_18 ,
V_47 ) ;
return - V_41 ;
}
V_52 = F_30 ( V_49 , 10 , & V_51 ) ;
if ( V_52 ) {
F_22 ( L_19 ,
V_48 , V_49 ) ;
return - V_41 ;
}
strncpy ( V_56 [ V_6 ] . V_30 , V_48 ,
V_57 - 1 ) ;
V_56 [ V_6 ++ ] . V_13 = ( int ) V_51 ;
if ( V_6 == V_58 ) {
F_22 ( L_20 ,
V_58 ) ;
return - V_41 ;
}
}
if ( V_56 [ 0 ] . V_30 [ 0 ] )
V_13 = V_56 ;
if ( V_38 > 2 )
F_12 () ;
if ( V_38 > 2 )
F_16 () ;
F_13 ( L_21 , V_30 , V_59 , V_36 ) ;
if ( V_60 > 0 && V_60 < 4 ) {
V_60 = ( 4 - V_60 ) * 90 ;
F_31 ( L_22 ,
V_60 ) ;
}
if ( V_60 != 0 && V_60 != 90 && V_60 != 180 && V_60 != 270 ) {
F_31 ( L_23 ,
V_60 ) ;
V_60 = 0 ;
}
if ( strncmp ( V_30 , L_24 , V_57 ) == 0 ) {
F_32 ( L_25 ) ;
for ( V_6 = 0 ; V_6 < F_33 ( V_61 ) ; V_6 ++ )
F_32 ( L_26 , V_61 [ V_6 ] . V_30 ) ;
return - V_62 ;
}
if ( V_63 ) {
V_6 = F_33 ( V_61 ) - 1 ;
V_61 [ V_6 ] . V_30 = V_30 ;
if ( V_64 == 0 ) {
V_61 [ V_6 ] . V_29 -> V_30 = V_30 ;
V_61 [ V_6 ] . V_22 = NULL ;
} else {
strncpy ( V_61 [ V_6 ] . V_22 -> V_23 , V_30 , V_65 ) ;
V_61 [ V_6 ] . V_29 = NULL ;
}
}
for ( V_6 = 0 ; V_6 < F_33 ( V_61 ) ; V_6 ++ ) {
if ( strncmp ( V_30 , V_61 [ V_6 ] . V_30 , 32 ) == 0 ) {
if ( V_61 [ V_6 ] . V_22 ) {
V_22 = V_61 [ V_6 ] . V_22 ;
V_22 -> V_42 = V_36 ;
V_22 -> V_40 = V_59 ;
if ( V_64 )
V_22 -> V_24 = V_64 ;
if ( V_26 != - 1 )
V_22 -> V_26 = V_26 ;
V_45 = ( void * ) V_22 -> V_32 ;
} else if ( V_61 [ V_6 ] . V_29 ) {
V_66 = V_61 [ V_6 ] . V_29 ;
V_45 = V_66 -> V_20 . V_32 ;
} else {
F_22 ( L_27 ) ;
return - V_41 ;
}
V_45 -> V_60 = V_60 ;
if ( V_67 == 0 )
V_45 -> V_67 = false ;
else if ( V_67 == 1 )
V_45 -> V_67 = true ;
if ( V_68 )
V_45 -> V_68 = V_68 ;
if ( gamma )
V_45 -> gamma = gamma ;
V_45 -> V_69 . V_70 = V_70 ;
if ( V_71 )
V_45 -> V_71 = V_71 ;
if ( V_72 )
V_45 -> V_72 = V_72 ;
if ( V_53 )
V_45 -> V_69 . V_73 = V_74 ;
if ( V_13 )
V_45 -> V_55 = V_13 ;
if ( V_63 ) {
V_45 -> V_69 . V_75 = V_75 ;
V_45 -> V_69 . V_76 = V_76 ;
V_45 -> V_69 . V_77 = V_77 ;
V_45 -> V_69 . V_78 = 1 ;
}
if ( V_61 [ V_6 ] . V_22 ) {
V_52 = F_20 ( V_22 ) ;
if ( V_52 ) {
F_22 ( L_28 ) ;
return V_52 ;
}
} else {
V_52 = F_34 ( V_66 ) ;
if ( V_52 < 0 ) {
F_22 ( L_29 ,
V_52 ) ;
return V_52 ;
}
}
V_50 = true ;
break;
}
}
if ( ! V_50 ) {
F_22 ( L_30 , V_30 ) ;
return - V_41 ;
}
if ( V_38 && V_45 && V_45 -> V_55 ) {
V_13 = V_45 -> V_55 ;
F_32 ( L_31 , V_30 ) ;
V_50 = false ;
while ( V_38 && V_13 -> V_30 [ 0 ] ) {
F_32 ( L_32 , V_13 -> V_30 , V_13 -> V_13 ) ;
V_13 ++ ;
V_50 = true ;
}
if ( ! V_50 )
F_32 ( L_33 ) ;
}
if ( V_21 && ( V_38 > 1 ) )
F_12 () ;
if ( V_66 && ( V_38 > 1 ) )
F_16 () ;
return 0 ;
}
static void T_4 F_35 ( void )
{
if ( V_21 ) {
F_19 ( & V_21 -> V_20 ) ;
F_36 ( V_21 ) ;
}
if ( V_66 )
F_37 ( V_66 ) ;
}
