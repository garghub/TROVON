static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 ,
V_2 ) ;
unsigned long V_5 ;
F_3 ( & V_4 -> V_6 ) ;
V_4 -> V_7 &= ~ ( V_8 | V_9 |
V_10 | V_11 ) ;
F_4 ( & V_4 -> V_12 , V_5 ) ;
V_4 -> V_7 |= V_4 -> V_13 << V_14 ;
if ( V_4 -> V_15 ) {
V_4 -> V_7 |= 2 << V_16 ;
V_4 -> V_7 |= V_4 -> V_17 << V_18 ;
V_4 -> V_7 |= V_4 -> V_19 ;
} else {
if ( V_4 -> V_20 != V_21 )
V_4 -> V_7 |= 1 << V_16 ;
}
F_5 ( & V_4 -> V_12 , V_5 ) ;
F_6 ( V_4 -> V_22 , V_4 -> V_23 , V_4 -> V_7 ) ;
F_7 ( & V_4 -> V_6 ) ;
}
static void F_8 ( struct V_24 * V_25 ,
enum V_26 V_27 )
{
struct V_3 * V_4 = F_9 ( V_25 ) ;
unsigned long V_5 ;
F_4 ( & V_4 -> V_12 , V_5 ) ;
V_4 -> V_20 = V_27 ;
if ( V_27 == V_21 )
V_4 -> V_15 = 0 ;
F_10 ( & V_4 -> V_2 ) ;
F_5 ( & V_4 -> V_12 , V_5 ) ;
}
static int F_11 ( struct V_24 * V_25 ,
unsigned long * V_28 ,
unsigned long * V_29 )
{
struct V_3 * V_4 = F_9 ( V_25 ) ;
unsigned long V_5 ;
int V_30 = 0 ;
if ( * V_28 == 0 && * V_29 == 0 ) {
* V_28 = 250 ;
* V_29 = 250 ;
}
F_4 ( & V_4 -> V_12 , V_5 ) ;
switch ( * V_28 ) {
case 1000 :
V_4 -> V_17 = 0 ;
break;
case 250 :
V_4 -> V_17 = 1 ;
break;
case 125 :
V_4 -> V_17 = 2 ;
break;
case 62 :
case 63 :
V_4 -> V_17 = 3 ;
break;
default:
V_30 = - V_31 ;
break;
}
if ( V_30 == 0 ) {
switch ( * V_29 / * V_28 ) {
case 1 :
V_4 -> V_19 = 0 ;
break;
case 3 :
V_4 -> V_19 = 1 ;
break;
case 4 :
V_4 -> V_19 = 2 ;
break;
case 8 :
V_4 -> V_19 = 3 ;
break;
default:
V_30 = - V_31 ;
break;
}
}
if ( V_30 == 0 )
V_4 -> V_15 = 1 ;
else
V_4 -> V_15 = 0 ;
F_10 ( & V_4 -> V_2 ) ;
F_5 ( & V_4 -> V_12 , V_5 ) ;
return V_30 ;
}
static T_1 F_12 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_36 )
{
struct V_24 * V_25 = F_13 ( V_33 ) ;
struct V_3 * V_4 = F_9 ( V_25 ) ;
int V_37 ;
T_1 V_30 = 0 ;
F_3 ( & V_4 -> V_6 ) ;
for ( V_37 = 0 ; V_37 < F_14 ( V_38 ) ; V_37 ++ )
if ( V_37 == V_4 -> V_13 )
V_30 += sprintf ( & V_36 [ V_30 ] , L_1 , V_38 [ V_37 ] ) ;
else
V_30 += sprintf ( & V_36 [ V_30 ] , L_2 , V_38 [ V_37 ] ) ;
F_7 ( & V_4 -> V_6 ) ;
V_30 += sprintf ( & V_36 [ V_30 ] , L_3 ) ;
return V_30 ;
}
static T_1 F_15 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_2 V_39 )
{
struct V_24 * V_25 = F_13 ( V_33 ) ;
struct V_3 * V_4 = F_9 ( V_25 ) ;
char V_40 [ 20 ] ;
int V_37 ;
T_2 V_41 ;
V_40 [ sizeof( V_40 ) - 1 ] = '\0' ;
strncpy ( V_40 , V_36 , sizeof( V_40 ) - 1 ) ;
V_41 = strlen ( V_40 ) ;
if ( V_41 && V_40 [ V_41 - 1 ] == '\n' )
V_40 [ V_41 - 1 ] = '\0' ;
for ( V_37 = 0 ; V_37 < F_14 ( V_38 ) ; V_37 ++ ) {
if ( ! strcmp ( V_40 , V_38 [ V_37 ] ) ) {
F_3 ( & V_4 -> V_6 ) ;
V_4 -> V_13 = V_37 ;
F_10 ( & V_4 -> V_2 ) ;
F_7 ( & V_4 -> V_6 ) ;
}
}
return V_39 ;
}
static int F_16 ( struct V_42 * V_43 )
{
struct V_22 * V_22 = F_13 ( V_43 -> V_33 . V_44 ) ;
struct V_45 * V_46 ;
struct V_47 V_48 ;
struct V_3 * V_49 ;
struct V_50 * V_51 ;
int V_52 = V_43 -> V_52 % F_14 ( V_46 -> V_53 ) ;
int V_30 ;
V_51 = F_17 ( V_43 , V_54 , 0 ) ;
if ( V_51 == NULL ) {
F_18 ( & V_43 -> V_33 , L_4 ) ;
V_30 = - V_31 ;
goto V_55;
}
V_49 = F_19 ( & V_43 -> V_33 , sizeof( struct V_3 ) ,
V_56 ) ;
if ( ! V_49 )
return - V_57 ;
F_20 ( V_43 , V_49 ) ;
V_49 -> V_22 = V_22 ;
V_49 -> V_23 = V_51 -> V_58 ;
if ( F_21 ( V_22 -> V_33 ) )
V_46 = F_21 ( V_22 -> V_33 ) ;
else
V_46 = NULL ;
memset ( & V_48 , 0 , sizeof( V_48 ) ) ;
if ( V_46 && V_46 -> V_53 [ V_52 ] )
memcpy ( & V_48 , V_46 -> V_53 [ V_52 ] , sizeof( V_48 ) ) ;
else
V_48 . V_40 = F_22 ( & V_43 -> V_33 ) ;
F_23 ( & V_49 -> V_6 ) ;
F_24 ( & V_49 -> V_2 , F_1 ) ;
F_25 ( & V_49 -> V_12 ) ;
V_49 -> V_7 = F_26 ( V_22 , V_49 -> V_23 ) ;
if ( V_49 -> V_7 & V_9 )
V_49 -> V_20 = V_59 ;
else
V_49 -> V_20 = V_21 ;
if ( V_48 . V_60 == V_61 ) {
V_49 -> V_13 = V_49 -> V_7 ;
V_49 -> V_13 &= V_8 ;
V_49 -> V_13 >>= V_14 ;
} else {
V_49 -> V_13 = V_48 . V_60 - 1 ;
}
V_49 -> V_62 . V_40 = V_48 . V_40 ;
V_49 -> V_62 . V_63 = V_48 . V_63 ;
V_49 -> V_62 . V_64 = F_8 ;
V_49 -> V_62 . V_65 = F_11 ;
V_30 = F_27 ( V_22 -> V_33 , & V_49 -> V_62 ) ;
if ( V_30 < 0 ) {
F_18 ( & V_43 -> V_33 , L_5 , V_30 ) ;
goto V_66;
}
V_30 = F_28 ( V_49 -> V_62 . V_33 , & V_67 ) ;
if ( V_30 != 0 )
F_18 ( & V_43 -> V_33 ,
L_6 , V_30 ) ;
return 0 ;
V_66:
F_29 ( & V_49 -> V_62 ) ;
V_55:
return V_30 ;
}
static int F_30 ( struct V_42 * V_43 )
{
struct V_3 * V_49 = F_31 ( V_43 ) ;
F_32 ( V_49 -> V_62 . V_33 , & V_67 ) ;
F_29 ( & V_49 -> V_62 ) ;
return 0 ;
}
