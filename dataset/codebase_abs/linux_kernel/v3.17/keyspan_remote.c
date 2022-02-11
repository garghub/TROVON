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
F_4 ( & V_2 -> V_13 -> V_2 ,
L_3 ,
V_14 , V_2 -> V_9 . V_11 , V_2 -> V_9 . V_12 ) ;
return - 1 ;
}
while ( ( V_2 -> V_9 . V_10 + 7 < ( sizeof( V_2 -> V_9 . V_15 ) * 8 ) ) &&
( V_2 -> V_9 . V_11 < V_2 -> V_9 . V_12 ) ) {
V_2 -> V_9 . V_15 += ( V_2 -> V_9 . V_16 [ V_2 -> V_9 . V_11 ++ ] << V_2 -> V_9 . V_10 ) ;
V_2 -> V_9 . V_10 += 8 ;
}
return 0 ;
}
static void F_5 ( struct V_1 * V_17 , int V_18 , int V_19 )
{
struct V_20 * V_21 = V_17 -> V_21 ;
F_6 ( V_21 , V_22 , V_23 , V_18 ) ;
F_7 ( V_21 , V_17 -> V_24 [ V_18 ] , V_19 ) ;
F_8 ( V_21 ) ;
}
static void F_9 ( struct V_1 * V_17 )
{
int V_5 ;
int V_25 = 0 ;
struct V_26 V_27 ;
switch( V_17 -> V_28 ) {
case 0 :
for ( V_5 = 0 ; V_5 < V_4 && V_17 -> V_6 [ V_5 ] == V_29 ; ++ V_5 ) ;
if ( V_5 < V_4 ) {
memcpy ( V_17 -> V_9 . V_16 , V_17 -> V_6 , V_4 ) ;
V_17 -> V_9 . V_12 = V_4 ;
V_17 -> V_9 . V_11 = 0 ;
V_17 -> V_9 . V_15 = 0 ;
V_17 -> V_9 . V_10 = 0 ;
V_17 -> V_28 = 1 ;
}
break;
case 1 :
memcpy ( V_17 -> V_9 . V_16 + V_17 -> V_9 . V_12 , V_17 -> V_6 , V_4 ) ;
V_17 -> V_9 . V_12 += V_4 ;
V_25 = 0 ;
while ( ( V_17 -> V_9 . V_10 >= 14 || V_17 -> V_9 . V_11 < V_17 -> V_9 . V_12 ) && ! V_25 ) {
for ( V_5 = 0 ; V_5 < 8 ; ++ V_5 ) {
if ( F_3 ( V_17 , 14 ) != 0 ) {
V_17 -> V_28 = 0 ;
return;
}
if ( ( V_17 -> V_9 . V_15 & V_30 ) == V_31 ) {
V_17 -> V_9 . V_15 = V_17 -> V_9 . V_15 >> 14 ;
V_17 -> V_9 . V_10 -= 14 ;
V_25 = 1 ;
break;
} else {
V_17 -> V_9 . V_15 = V_17 -> V_9 . V_15 >> 1 ;
-- V_17 -> V_9 . V_10 ;
}
}
}
if ( ! V_25 ) {
V_17 -> V_28 = 0 ;
V_17 -> V_9 . V_12 = 0 ;
} else {
V_17 -> V_28 = 2 ;
}
break;
case 2 :
memcpy ( V_17 -> V_9 . V_16 + V_17 -> V_9 . V_12 , V_17 -> V_6 , V_4 ) ;
V_17 -> V_9 . V_12 += V_4 ;
V_27 . system = 0 ;
for ( V_5 = 0 ; V_5 < 9 ; V_5 ++ ) {
F_3 ( V_17 , 6 ) ;
if ( ( V_17 -> V_9 . V_15 & V_32 ) == V_33 ) {
V_27 . system = V_27 . system << 1 ;
V_17 -> V_9 . V_15 = V_17 -> V_9 . V_15 >> 5 ;
V_17 -> V_9 . V_10 -= 5 ;
} else if ( ( V_17 -> V_9 . V_15 & V_34 ) == V_35 ) {
V_27 . system = ( V_27 . system << 1 ) + 1 ;
V_17 -> V_9 . V_15 = V_17 -> V_9 . V_15 >> 6 ;
V_17 -> V_9 . V_10 -= 6 ;
} else {
F_10 ( & V_17 -> V_13 -> V_2 ,
L_4 ,
V_14 ) ;
V_17 -> V_28 = 0 ;
return;
}
}
V_27 . V_18 = 0 ;
for ( V_5 = 0 ; V_5 < 5 ; V_5 ++ ) {
F_3 ( V_17 , 6 ) ;
if ( ( V_17 -> V_9 . V_15 & V_32 ) == V_33 ) {
V_27 . V_18 = V_27 . V_18 << 1 ;
V_17 -> V_9 . V_15 = V_17 -> V_9 . V_15 >> 5 ;
V_17 -> V_9 . V_10 -= 5 ;
} else if ( ( V_17 -> V_9 . V_15 & V_34 ) == V_35 ) {
V_27 . V_18 = ( V_27 . V_18 << 1 ) + 1 ;
V_17 -> V_9 . V_15 = V_17 -> V_9 . V_15 >> 6 ;
V_17 -> V_9 . V_10 -= 6 ;
} else {
F_10 ( & V_17 -> V_13 -> V_2 ,
L_5 ,
V_14 ) ;
V_17 -> V_28 = 0 ;
return;
}
}
F_3 ( V_17 , 6 ) ;
if ( ( V_17 -> V_9 . V_15 & V_32 ) == V_33 ) {
V_27 . V_36 = 0 ;
V_17 -> V_9 . V_15 = V_17 -> V_9 . V_15 >> 5 ;
V_17 -> V_9 . V_10 -= 5 ;
} else if ( ( V_17 -> V_9 . V_15 & V_34 ) == V_35 ) {
V_27 . V_36 = 1 ;
V_17 -> V_9 . V_15 = V_17 -> V_9 . V_15 >> 6 ;
V_17 -> V_9 . V_10 -= 6 ;
} else {
F_10 ( & V_17 -> V_13 -> V_2 ,
L_6 ,
V_14 ) ;
V_17 -> V_28 = 0 ;
return;
}
F_3 ( V_17 , 5 ) ;
if ( ( V_17 -> V_9 . V_15 & V_37 ) == V_38 ) {
V_17 -> V_9 . V_15 = V_17 -> V_9 . V_15 >> 5 ;
V_17 -> V_9 . V_10 -= 5 ;
} else {
F_10 ( & V_17 -> V_13 -> V_2 ,
L_7 ) ;
}
F_4 ( & V_17 -> V_13 -> V_2 ,
L_8 ,
V_14 , V_27 . system , V_27 . V_18 , V_27 . V_36 ) ;
if ( V_27 . V_36 != V_17 -> V_36 ) {
F_5 ( V_17 , V_27 . V_18 , 1 ) ;
F_5 ( V_17 , V_27 . V_18 , 0 ) ;
V_17 -> V_36 = V_27 . V_36 ;
}
V_17 -> V_28 = 0 ;
break;
}
}
static int F_11 ( struct V_39 * V_2 )
{
int V_40 = 0 ;
V_40 = F_12 ( V_2 , F_13 ( V_2 , 0 ) ,
0x11 , 0x40 , 0x5601 , 0x0 , NULL , 0 , 0 ) ;
if ( V_40 ) {
F_4 ( & V_2 -> V_2 , L_9 ,
V_14 , V_40 ) ;
return ( V_40 ) ;
}
V_40 = F_12 ( V_2 , F_13 ( V_2 , 0 ) ,
0x44 , 0x40 , 0x0 , 0x0 , NULL , 0 , 0 ) ;
if ( V_40 ) {
F_4 ( & V_2 -> V_2 , L_10 ,
V_14 , V_40 ) ;
return ( V_40 ) ;
}
V_40 = F_12 ( V_2 , F_13 ( V_2 , 0 ) ,
0x22 , 0x40 , 0x0 , 0x0 , NULL , 0 , 0 ) ;
if ( V_40 ) {
F_4 ( & V_2 -> V_2 , L_11 ,
V_14 , V_40 ) ;
return ( V_40 ) ;
}
F_4 ( & V_2 -> V_2 , L_12 , V_14 ) ;
return ( V_40 ) ;
}
static void F_14 ( struct V_41 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
int V_40 ;
switch ( V_41 -> V_43 ) {
case 0 :
break;
case - V_44 :
case - V_45 :
case - V_46 :
return;
default:
goto V_47;
}
if ( V_48 )
F_1 ( V_2 ) ;
F_9 ( V_2 ) ;
V_47:
V_40 = F_15 ( V_41 , V_49 ) ;
if ( V_40 )
F_10 ( & V_2 -> V_13 -> V_2 ,
L_13 ,
V_14 , V_40 ) ;
}
static int F_16 ( struct V_20 * V_2 )
{
struct V_1 * V_17 = F_17 ( V_2 ) ;
V_17 -> V_50 -> V_2 = V_17 -> V_7 ;
if ( F_15 ( V_17 -> V_50 , V_51 ) )
return - V_52 ;
return 0 ;
}
static void F_18 ( struct V_20 * V_2 )
{
struct V_1 * V_17 = F_17 ( V_2 ) ;
F_19 ( V_17 -> V_50 ) ;
}
static struct V_53 * F_20 ( struct V_54 * V_55 )
{
struct V_53 * V_56 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_55 -> V_57 . V_58 ; ++ V_5 ) {
V_56 = & V_55 -> V_56 [ V_5 ] . V_57 ;
if ( F_21 ( V_56 ) ) {
return V_56 ;
}
}
return NULL ;
}
static int F_22 ( struct V_59 * V_13 , const struct V_60 * V_61 )
{
struct V_39 * V_7 = F_23 ( V_13 ) ;
struct V_53 * V_56 ;
struct V_1 * V_17 ;
struct V_20 * V_20 ;
int V_5 , error ;
V_56 = F_20 ( V_13 -> V_62 ) ;
if ( ! V_56 )
return - V_63 ;
V_17 = F_24 ( sizeof( * V_17 ) , V_51 ) ;
V_20 = F_25 () ;
if ( ! V_17 || ! V_20 ) {
error = - V_64 ;
goto V_65;
}
V_17 -> V_7 = V_7 ;
V_17 -> V_21 = V_20 ;
V_17 -> V_13 = V_13 ;
V_17 -> V_66 = V_56 ;
V_17 -> V_36 = - 1 ;
V_17 -> V_6 = F_26 ( V_7 , V_4 , V_49 , & V_17 -> V_67 ) ;
if ( ! V_17 -> V_6 ) {
error = - V_64 ;
goto V_65;
}
V_17 -> V_50 = F_27 ( 0 , V_51 ) ;
if ( ! V_17 -> V_50 ) {
error = - V_64 ;
goto V_68;
}
error = F_11 ( V_7 ) ;
if ( error ) {
error = - V_63 ;
goto V_69;
}
if ( V_7 -> V_70 )
F_28 ( V_17 -> V_71 , V_7 -> V_70 , sizeof( V_17 -> V_71 ) ) ;
if ( V_7 -> V_72 ) {
if ( V_7 -> V_70 )
F_29 ( V_17 -> V_71 , L_14 , sizeof( V_17 -> V_71 ) ) ;
F_29 ( V_17 -> V_71 , V_7 -> V_72 , sizeof( V_17 -> V_71 ) ) ;
}
if ( ! strlen ( V_17 -> V_71 ) )
snprintf ( V_17 -> V_71 , sizeof( V_17 -> V_71 ) ,
L_15 ,
F_30 ( V_7 -> V_73 . V_74 ) ,
F_30 ( V_7 -> V_73 . V_75 ) ) ;
F_31 ( V_7 , V_17 -> V_76 , sizeof( V_17 -> V_76 ) ) ;
F_29 ( V_17 -> V_76 , L_16 , sizeof( V_17 -> V_76 ) ) ;
memcpy ( V_17 -> V_24 , V_77 , sizeof( V_17 -> V_24 ) ) ;
V_20 -> V_71 = V_17 -> V_71 ;
V_20 -> V_76 = V_17 -> V_76 ;
F_32 ( V_7 , & V_20 -> V_61 ) ;
V_20 -> V_2 . V_78 = & V_13 -> V_2 ;
V_20 -> V_79 = V_17 -> V_24 ;
V_20 -> V_80 = sizeof( unsigned short ) ;
V_20 -> V_81 = F_33 ( V_17 -> V_24 ) ;
F_34 ( V_20 , V_22 , V_23 ) ;
F_35 ( V_82 , V_20 -> V_83 ) ;
for ( V_5 = 0 ; V_5 < F_33 ( V_77 ) ; V_5 ++ )
F_35 ( V_77 [ V_5 ] , V_20 -> V_84 ) ;
F_36 ( V_85 , V_20 -> V_84 ) ;
F_37 ( V_20 , V_17 ) ;
V_20 -> V_86 = F_16 ;
V_20 -> V_87 = F_18 ;
F_38 ( V_17 -> V_50 ,
V_17 -> V_7 ,
F_39 ( V_17 -> V_7 , V_56 -> V_88 ) ,
V_17 -> V_6 , V_4 , F_14 , V_17 ,
V_56 -> V_89 ) ;
V_17 -> V_50 -> V_90 = V_17 -> V_67 ;
V_17 -> V_50 -> V_91 |= V_92 ;
error = F_40 ( V_17 -> V_21 ) ;
if ( error )
goto V_69;
F_41 ( V_13 , V_17 ) ;
return 0 ;
V_69: F_42 ( V_17 -> V_50 ) ;
V_68: F_43 ( V_7 , V_4 , V_17 -> V_6 , V_17 -> V_67 ) ;
V_65: F_44 ( V_17 ) ;
F_45 ( V_20 ) ;
return error ;
}
static void F_46 ( struct V_59 * V_13 )
{
struct V_1 * V_17 ;
V_17 = F_47 ( V_13 ) ;
F_41 ( V_13 , NULL ) ;
if ( V_17 ) {
F_48 ( V_17 -> V_21 ) ;
F_19 ( V_17 -> V_50 ) ;
F_42 ( V_17 -> V_50 ) ;
F_43 ( V_17 -> V_7 , V_4 , V_17 -> V_6 , V_17 -> V_67 ) ;
F_44 ( V_17 ) ;
}
}
