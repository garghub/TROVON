static void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_2 ( & V_2 -> V_4 ) ;
V_2 -> V_5 &= ~ ( V_6 | V_7 |
V_8 | V_9 ) ;
F_3 ( & V_2 -> V_10 , V_3 ) ;
V_2 -> V_5 |= V_2 -> V_11 << V_12 ;
if ( V_2 -> V_13 ) {
V_2 -> V_5 |= 2 << V_14 ;
V_2 -> V_5 |= V_2 -> V_15 << V_16 ;
V_2 -> V_5 |= V_2 -> V_17 ;
} else {
if ( V_2 -> V_18 != V_19 )
V_2 -> V_5 |= 1 << V_14 ;
}
F_4 ( & V_2 -> V_10 , V_3 ) ;
F_5 ( V_2 -> V_20 , V_2 -> V_21 , V_2 -> V_5 ) ;
F_6 ( & V_2 -> V_4 ) ;
}
static int F_7 ( struct V_22 * V_23 ,
enum V_24 V_25 )
{
struct V_1 * V_2 = F_8 ( V_23 ) ;
unsigned long V_3 ;
F_3 ( & V_2 -> V_10 , V_3 ) ;
V_2 -> V_18 = V_25 ;
if ( V_25 == V_19 )
V_2 -> V_13 = 0 ;
F_4 ( & V_2 -> V_10 , V_3 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_9 ( struct V_22 * V_23 ,
unsigned long * V_26 ,
unsigned long * V_27 )
{
struct V_1 * V_2 = F_8 ( V_23 ) ;
unsigned long V_3 ;
int V_28 = 0 ;
if ( * V_26 == 0 && * V_27 == 0 ) {
* V_26 = 250 ;
* V_27 = 250 ;
}
F_3 ( & V_2 -> V_10 , V_3 ) ;
switch ( * V_26 ) {
case 1000 :
V_2 -> V_15 = 0 ;
break;
case 250 :
V_2 -> V_15 = 1 ;
break;
case 125 :
V_2 -> V_15 = 2 ;
break;
case 62 :
case 63 :
V_2 -> V_15 = 3 ;
break;
default:
V_28 = - V_29 ;
break;
}
if ( V_28 == 0 ) {
switch ( * V_27 / * V_26 ) {
case 1 :
V_2 -> V_17 = 0 ;
break;
case 3 :
V_2 -> V_17 = 1 ;
break;
case 4 :
V_2 -> V_17 = 2 ;
break;
case 8 :
V_2 -> V_17 = 3 ;
break;
default:
V_28 = - V_29 ;
break;
}
}
if ( V_28 == 0 )
V_2 -> V_13 = 1 ;
else
V_2 -> V_13 = 0 ;
F_4 ( & V_2 -> V_10 , V_3 ) ;
F_1 ( V_2 ) ;
return V_28 ;
}
static T_1 F_10 ( struct V_30 * V_31 ,
struct V_32 * V_33 , char * V_34 )
{
struct V_22 * V_23 = F_11 ( V_31 ) ;
struct V_1 * V_2 = F_8 ( V_23 ) ;
int V_35 ;
T_1 V_28 = 0 ;
F_2 ( & V_2 -> V_4 ) ;
for ( V_35 = 0 ; V_35 < F_12 ( V_36 ) ; V_35 ++ )
if ( V_35 == V_2 -> V_11 )
V_28 += sprintf ( & V_34 [ V_28 ] , L_1 , V_36 [ V_35 ] ) ;
else
V_28 += sprintf ( & V_34 [ V_28 ] , L_2 , V_36 [ V_35 ] ) ;
F_6 ( & V_2 -> V_4 ) ;
V_28 += sprintf ( & V_34 [ V_28 ] , L_3 ) ;
return V_28 ;
}
static T_1 F_13 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
const char * V_34 , T_2 V_37 )
{
struct V_22 * V_23 = F_11 ( V_31 ) ;
struct V_1 * V_2 = F_8 ( V_23 ) ;
char V_38 [ 20 ] ;
int V_35 ;
T_2 V_39 ;
V_38 [ sizeof( V_38 ) - 1 ] = '\0' ;
strncpy ( V_38 , V_34 , sizeof( V_38 ) - 1 ) ;
V_39 = strlen ( V_38 ) ;
if ( V_39 && V_38 [ V_39 - 1 ] == '\n' )
V_38 [ V_39 - 1 ] = '\0' ;
for ( V_35 = 0 ; V_35 < F_12 ( V_36 ) ; V_35 ++ ) {
if ( ! strcmp ( V_38 , V_36 [ V_35 ] ) ) {
F_2 ( & V_2 -> V_4 ) ;
V_2 -> V_11 = V_35 ;
F_6 ( & V_2 -> V_4 ) ;
F_1 ( V_2 ) ;
}
}
return V_37 ;
}
static int F_14 ( struct V_40 * V_41 )
{
struct V_20 * V_20 = F_11 ( V_41 -> V_31 . V_42 ) ;
struct V_43 * V_44 ;
struct V_45 V_46 ;
struct V_1 * V_47 ;
struct V_48 * V_49 ;
int V_50 = V_41 -> V_50 % F_12 ( V_44 -> V_51 ) ;
int V_28 ;
V_49 = F_15 ( V_41 , V_52 , 0 ) ;
if ( V_49 == NULL ) {
F_16 ( & V_41 -> V_31 , L_4 ) ;
return - V_29 ;
}
V_47 = F_17 ( & V_41 -> V_31 , sizeof( struct V_1 ) ,
V_53 ) ;
if ( ! V_47 )
return - V_54 ;
V_47 -> V_20 = V_20 ;
V_47 -> V_21 = V_49 -> V_55 ;
if ( F_18 ( V_20 -> V_31 ) )
V_44 = F_18 ( V_20 -> V_31 ) ;
else
V_44 = NULL ;
memset ( & V_46 , 0 , sizeof( V_46 ) ) ;
if ( V_44 && V_44 -> V_51 [ V_50 ] )
memcpy ( & V_46 , V_44 -> V_51 [ V_50 ] , sizeof( V_46 ) ) ;
else
V_46 . V_38 = F_19 ( & V_41 -> V_31 ) ;
F_20 ( & V_47 -> V_4 ) ;
F_21 ( & V_47 -> V_10 ) ;
V_47 -> V_5 = F_22 ( V_20 , V_47 -> V_21 ) ;
if ( V_47 -> V_5 & V_7 )
V_47 -> V_18 = V_56 ;
else
V_47 -> V_18 = V_19 ;
if ( V_46 . V_57 == V_58 ) {
V_47 -> V_11 = V_47 -> V_5 ;
V_47 -> V_11 &= V_6 ;
V_47 -> V_11 >>= V_12 ;
} else {
V_47 -> V_11 = V_46 . V_57 - 1 ;
}
V_47 -> V_59 . V_38 = V_46 . V_38 ;
V_47 -> V_59 . V_60 = V_46 . V_60 ;
V_47 -> V_59 . V_61 = F_7 ;
V_47 -> V_59 . V_62 = F_9 ;
V_47 -> V_59 . V_63 = V_64 ;
V_28 = F_23 ( V_20 -> V_31 , & V_47 -> V_59 ) ;
if ( V_28 < 0 ) {
F_16 ( & V_41 -> V_31 , L_5 , V_28 ) ;
return V_28 ;
}
return 0 ;
}
