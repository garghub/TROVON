static void F_1 ( struct V_1 * V_2 )
{
char V_3 [ 4 * V_4 ] ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_4 ; V_5 ++ )
snprintf ( V_3 + V_5 * 3 , 4 , L_1 , V_2 -> V_6 [ V_5 ] ) ;
F_2 ( & V_2 -> V_7 -> V_2 , L_2 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 , int V_8 )
{
if ( V_2 -> V_9 . V_10 >= V_8 )
return 0 ;
if ( V_2 -> V_9 . V_11 >= V_2 -> V_9 . V_12 ) {
F_4 ( & V_2 -> V_7 -> V_2 ,
L_3 ,
V_13 , V_2 -> V_9 . V_11 , V_2 -> V_9 . V_12 ) ;
return - 1 ;
}
while ( ( V_2 -> V_9 . V_10 + 7 < ( sizeof( V_2 -> V_9 . V_14 ) * 8 ) ) &&
( V_2 -> V_9 . V_11 < V_2 -> V_9 . V_12 ) ) {
V_2 -> V_9 . V_14 += ( V_2 -> V_9 . V_15 [ V_2 -> V_9 . V_11 ++ ] << V_2 -> V_9 . V_10 ) ;
V_2 -> V_9 . V_10 += 8 ;
}
return 0 ;
}
static void F_5 ( struct V_1 * V_16 , int V_17 , int V_18 )
{
struct V_19 * V_20 = V_16 -> V_20 ;
F_6 ( V_20 , V_21 , V_22 , V_17 ) ;
F_7 ( V_20 , V_16 -> V_23 [ V_17 ] , V_18 ) ;
F_8 ( V_20 ) ;
}
static void F_9 ( struct V_1 * V_16 )
{
int V_5 ;
int V_24 = 0 ;
struct V_25 V_26 ;
switch( V_16 -> V_27 ) {
case 0 :
for ( V_5 = 0 ; V_5 < V_4 && V_16 -> V_6 [ V_5 ] == V_28 ; ++ V_5 ) ;
if ( V_5 < V_4 ) {
memcpy ( V_16 -> V_9 . V_15 , V_16 -> V_6 , V_4 ) ;
V_16 -> V_9 . V_12 = V_4 ;
V_16 -> V_9 . V_11 = 0 ;
V_16 -> V_9 . V_14 = 0 ;
V_16 -> V_9 . V_10 = 0 ;
V_16 -> V_27 = 1 ;
}
break;
case 1 :
memcpy ( V_16 -> V_9 . V_15 + V_16 -> V_9 . V_12 , V_16 -> V_6 , V_4 ) ;
V_16 -> V_9 . V_12 += V_4 ;
V_24 = 0 ;
while ( ( V_16 -> V_9 . V_10 >= 14 || V_16 -> V_9 . V_11 < V_16 -> V_9 . V_12 ) && ! V_24 ) {
for ( V_5 = 0 ; V_5 < 8 ; ++ V_5 ) {
if ( F_3 ( V_16 , 14 ) != 0 ) {
V_16 -> V_27 = 0 ;
return;
}
if ( ( V_16 -> V_9 . V_14 & V_29 ) == V_30 ) {
V_16 -> V_9 . V_14 = V_16 -> V_9 . V_14 >> 14 ;
V_16 -> V_9 . V_10 -= 14 ;
V_24 = 1 ;
break;
} else {
V_16 -> V_9 . V_14 = V_16 -> V_9 . V_14 >> 1 ;
-- V_16 -> V_9 . V_10 ;
}
}
}
if ( ! V_24 ) {
V_16 -> V_27 = 0 ;
V_16 -> V_9 . V_12 = 0 ;
} else {
V_16 -> V_27 = 2 ;
}
break;
case 2 :
memcpy ( V_16 -> V_9 . V_15 + V_16 -> V_9 . V_12 , V_16 -> V_6 , V_4 ) ;
V_16 -> V_9 . V_12 += V_4 ;
V_26 . system = 0 ;
for ( V_5 = 0 ; V_5 < 9 ; V_5 ++ ) {
F_3 ( V_16 , 6 ) ;
if ( ( V_16 -> V_9 . V_14 & V_31 ) == V_32 ) {
V_26 . system = V_26 . system << 1 ;
V_16 -> V_9 . V_14 = V_16 -> V_9 . V_14 >> 5 ;
V_16 -> V_9 . V_10 -= 5 ;
} else if ( ( V_16 -> V_9 . V_14 & V_33 ) == V_34 ) {
V_26 . system = ( V_26 . system << 1 ) + 1 ;
V_16 -> V_9 . V_14 = V_16 -> V_9 . V_14 >> 6 ;
V_16 -> V_9 . V_10 -= 6 ;
} else {
F_10 ( L_4 , V_13 ) ;
V_16 -> V_27 = 0 ;
return;
}
}
V_26 . V_17 = 0 ;
for ( V_5 = 0 ; V_5 < 5 ; V_5 ++ ) {
F_3 ( V_16 , 6 ) ;
if ( ( V_16 -> V_9 . V_14 & V_31 ) == V_32 ) {
V_26 . V_17 = V_26 . V_17 << 1 ;
V_16 -> V_9 . V_14 = V_16 -> V_9 . V_14 >> 5 ;
V_16 -> V_9 . V_10 -= 5 ;
} else if ( ( V_16 -> V_9 . V_14 & V_33 ) == V_34 ) {
V_26 . V_17 = ( V_26 . V_17 << 1 ) + 1 ;
V_16 -> V_9 . V_14 = V_16 -> V_9 . V_14 >> 6 ;
V_16 -> V_9 . V_10 -= 6 ;
} else {
F_10 ( L_5 , V_13 ) ;
V_16 -> V_27 = 0 ;
return;
}
}
F_3 ( V_16 , 6 ) ;
if ( ( V_16 -> V_9 . V_14 & V_31 ) == V_32 ) {
V_26 . V_35 = 0 ;
V_16 -> V_9 . V_14 = V_16 -> V_9 . V_14 >> 5 ;
V_16 -> V_9 . V_10 -= 5 ;
} else if ( ( V_16 -> V_9 . V_14 & V_33 ) == V_34 ) {
V_26 . V_35 = 1 ;
V_16 -> V_9 . V_14 = V_16 -> V_9 . V_14 >> 6 ;
V_16 -> V_9 . V_10 -= 6 ;
} else {
F_10 ( L_6 , V_13 ) ;
V_16 -> V_27 = 0 ;
return;
}
F_3 ( V_16 , 5 ) ;
if ( ( V_16 -> V_9 . V_14 & V_36 ) == V_37 ) {
V_16 -> V_9 . V_14 = V_16 -> V_9 . V_14 >> 5 ;
V_16 -> V_9 . V_10 -= 5 ;
} else {
F_10 ( L_7 ) ;
}
F_4 ( & V_16 -> V_7 -> V_2 ,
L_8 ,
V_13 , V_26 . system , V_26 . V_17 , V_26 . V_35 ) ;
if ( V_26 . V_35 != V_16 -> V_35 ) {
F_5 ( V_16 , V_26 . V_17 , 1 ) ;
F_5 ( V_16 , V_26 . V_17 , 0 ) ;
V_16 -> V_35 = V_26 . V_35 ;
}
V_16 -> V_27 = 0 ;
break;
}
}
static int F_11 ( struct V_38 * V_2 )
{
int V_39 = 0 ;
V_39 = F_12 ( V_2 , F_13 ( V_2 , 0 ) ,
0x11 , 0x40 , 0x5601 , 0x0 , NULL , 0 , 0 ) ;
if ( V_39 ) {
F_4 ( & V_2 -> V_2 , L_9 ,
V_13 , V_39 ) ;
return ( V_39 ) ;
}
V_39 = F_12 ( V_2 , F_13 ( V_2 , 0 ) ,
0x44 , 0x40 , 0x0 , 0x0 , NULL , 0 , 0 ) ;
if ( V_39 ) {
F_4 ( & V_2 -> V_2 , L_10 ,
V_13 , V_39 ) ;
return ( V_39 ) ;
}
V_39 = F_12 ( V_2 , F_13 ( V_2 , 0 ) ,
0x22 , 0x40 , 0x0 , 0x0 , NULL , 0 , 0 ) ;
if ( V_39 ) {
F_4 ( & V_2 -> V_2 , L_11 ,
V_13 , V_39 ) ;
return ( V_39 ) ;
}
F_4 ( & V_2 -> V_2 , L_12 , V_13 ) ;
return ( V_39 ) ;
}
static void F_14 ( struct V_40 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_41 ;
int V_39 ;
switch ( V_40 -> V_42 ) {
case 0 :
break;
case - V_43 :
case - V_44 :
case - V_45 :
return;
default:
goto V_46;
break;
}
if ( V_47 )
F_1 ( V_2 ) ;
F_9 ( V_2 ) ;
V_46:
V_39 = F_15 ( V_40 , V_48 ) ;
if ( V_39 )
F_10 ( L_13 , V_13 , V_39 ) ;
}
static int F_16 ( struct V_19 * V_2 )
{
struct V_1 * V_16 = F_17 ( V_2 ) ;
V_16 -> V_49 -> V_2 = V_16 -> V_7 ;
if ( F_15 ( V_16 -> V_49 , V_50 ) )
return - V_51 ;
return 0 ;
}
static void F_18 ( struct V_19 * V_2 )
{
struct V_1 * V_16 = F_17 ( V_2 ) ;
F_19 ( V_16 -> V_49 ) ;
}
static struct V_52 * F_20 ( struct V_53 * V_54 )
{
struct V_52 * V_55 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_54 -> V_56 . V_57 ; ++ V_5 ) {
V_55 = & V_54 -> V_55 [ V_5 ] . V_56 ;
if ( F_21 ( V_55 ) ) {
return V_55 ;
}
}
return NULL ;
}
static int F_22 ( struct V_58 * V_59 , const struct V_60 * V_61 )
{
struct V_38 * V_7 = F_23 ( V_59 ) ;
struct V_52 * V_55 ;
struct V_1 * V_16 ;
struct V_19 * V_19 ;
int V_5 , error ;
V_55 = F_20 ( V_59 -> V_62 ) ;
if ( ! V_55 )
return - V_63 ;
V_16 = F_24 ( sizeof( * V_16 ) , V_50 ) ;
V_19 = F_25 () ;
if ( ! V_16 || ! V_19 ) {
error = - V_64 ;
goto V_65;
}
V_16 -> V_7 = V_7 ;
V_16 -> V_20 = V_19 ;
V_16 -> V_59 = V_59 ;
V_16 -> V_66 = V_55 ;
V_16 -> V_35 = - 1 ;
V_16 -> V_6 = F_26 ( V_7 , V_4 , V_48 , & V_16 -> V_67 ) ;
if ( ! V_16 -> V_6 ) {
error = - V_64 ;
goto V_65;
}
V_16 -> V_49 = F_27 ( 0 , V_50 ) ;
if ( ! V_16 -> V_49 ) {
error = - V_64 ;
goto V_68;
}
error = F_11 ( V_7 ) ;
if ( error ) {
error = - V_63 ;
goto V_69;
}
if ( V_7 -> V_70 )
F_28 ( V_16 -> V_71 , V_7 -> V_70 , sizeof( V_16 -> V_71 ) ) ;
if ( V_7 -> V_72 ) {
if ( V_7 -> V_70 )
F_29 ( V_16 -> V_71 , L_14 , sizeof( V_16 -> V_71 ) ) ;
F_29 ( V_16 -> V_71 , V_7 -> V_72 , sizeof( V_16 -> V_71 ) ) ;
}
if ( ! strlen ( V_16 -> V_71 ) )
snprintf ( V_16 -> V_71 , sizeof( V_16 -> V_71 ) ,
L_15 ,
F_30 ( V_7 -> V_73 . V_74 ) ,
F_30 ( V_7 -> V_73 . V_75 ) ) ;
F_31 ( V_7 , V_16 -> V_76 , sizeof( V_16 -> V_76 ) ) ;
F_29 ( V_16 -> V_76 , L_16 , sizeof( V_16 -> V_76 ) ) ;
memcpy ( V_16 -> V_23 , V_77 , sizeof( V_16 -> V_23 ) ) ;
V_19 -> V_71 = V_16 -> V_71 ;
V_19 -> V_76 = V_16 -> V_76 ;
F_32 ( V_7 , & V_19 -> V_61 ) ;
V_19 -> V_2 . V_78 = & V_59 -> V_2 ;
V_19 -> V_79 = V_16 -> V_23 ;
V_19 -> V_80 = sizeof( unsigned short ) ;
V_19 -> V_81 = F_33 ( V_16 -> V_23 ) ;
F_34 ( V_19 , V_21 , V_22 ) ;
F_35 ( V_82 , V_19 -> V_83 ) ;
for ( V_5 = 0 ; V_5 < F_33 ( V_77 ) ; V_5 ++ )
F_35 ( V_77 [ V_5 ] , V_19 -> V_84 ) ;
F_36 ( V_85 , V_19 -> V_84 ) ;
F_37 ( V_19 , V_16 ) ;
V_19 -> V_86 = F_16 ;
V_19 -> V_87 = F_18 ;
F_38 ( V_16 -> V_49 ,
V_16 -> V_7 ,
F_39 ( V_16 -> V_7 , V_55 -> V_88 ) ,
V_16 -> V_6 , V_4 , F_14 , V_16 ,
V_55 -> V_89 ) ;
V_16 -> V_49 -> V_90 = V_16 -> V_67 ;
V_16 -> V_49 -> V_91 |= V_92 ;
error = F_40 ( V_16 -> V_20 ) ;
if ( error )
goto V_69;
F_41 ( V_59 , V_16 ) ;
return 0 ;
V_69: F_42 ( V_16 -> V_49 ) ;
V_68: F_43 ( V_7 , V_4 , V_16 -> V_6 , V_16 -> V_67 ) ;
V_65: F_44 ( V_16 ) ;
F_45 ( V_19 ) ;
return error ;
}
static void F_46 ( struct V_58 * V_59 )
{
struct V_1 * V_16 ;
V_16 = F_47 ( V_59 ) ;
F_41 ( V_59 , NULL ) ;
if ( V_16 ) {
F_48 ( V_16 -> V_20 ) ;
F_19 ( V_16 -> V_49 ) ;
F_42 ( V_16 -> V_49 ) ;
F_43 ( V_16 -> V_7 , V_4 , V_16 -> V_6 , V_16 -> V_67 ) ;
F_44 ( V_16 ) ;
}
}
static int T_1 F_49 ( void )
{
int V_93 ;
V_93 = F_50 ( & V_94 ) ;
if ( V_93 )
F_10 ( L_17 , V_93 ) ;
return V_93 ;
}
static void T_2 F_51 ( void )
{
F_52 ( & V_94 ) ;
}
