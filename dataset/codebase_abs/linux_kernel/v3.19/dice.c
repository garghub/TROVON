static int F_1 ( struct V_1 * V_2 )
{
static const int V_3 [ 10 ] = {
10 , 0x64 / 4 ,
10 , 0x18 / 4 ,
10 , 0x18 / 4 ,
0 , 0 ,
0 , 0 ,
} ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 V_7 ;
int V_8 , V_9 , V_10 = - 1 , V_11 = - 1 , V_12 ;
unsigned int V_13 , V_14 ;
T_1 * V_15 , V_16 ;
T_1 V_17 ;
V_15 = F_3 ( F_4 ( V_3 ) , sizeof( T_1 ) ,
V_18 ) ;
if ( V_15 == NULL )
return - V_19 ;
F_5 ( & V_7 , V_2 -> V_20 ) ;
while ( F_6 ( & V_7 , & V_8 , & V_9 ) ) {
switch ( V_8 ) {
case V_21 :
V_10 = V_9 ;
break;
case V_22 :
V_11 = V_9 ;
break;
}
}
if ( V_10 == V_23 )
V_13 = V_24 ;
else
V_13 = V_25 ;
if ( V_5 -> V_26 [ 3 ] != ( ( V_10 << 8 ) | V_13 ) ||
V_5 -> V_26 [ 4 ] >> 22 != V_11 ) {
V_12 = - V_27 ;
goto V_28;
}
V_12 = F_7 ( V_2 , V_29 ,
V_30 , V_15 ,
sizeof( T_1 ) * F_4 ( V_3 ) , 0 ) ;
if ( V_12 < 0 ) {
V_12 = - V_27 ;
goto V_28;
}
for ( V_14 = 0 ; V_14 < F_4 ( V_3 ) ; ++ V_14 ) {
V_16 = F_8 ( V_15 [ V_14 ] ) ;
if ( V_16 < V_3 [ V_14 ] || V_16 >= 0x40000 ) {
V_12 = - V_27 ;
goto V_28;
}
}
V_12 = F_7 ( V_2 , V_31 ,
V_30 +
F_8 ( V_15 [ 0 ] ) * 4 + V_32 ,
& V_17 , 4 , 0 ) ;
if ( V_12 < 0 ) {
V_12 = - V_27 ;
goto V_28;
}
if ( ( V_17 & F_9 ( 0xff000000 ) ) != F_9 ( 0x01000000 ) ) {
F_10 ( & V_2 -> V_5 ,
L_1 , F_8 ( V_17 ) ) ;
V_12 = - V_27 ;
goto V_28;
}
V_28:
return V_12 ;
}
static int F_11 ( struct V_33 * V_34 ,
unsigned int V_35 , unsigned int * V_36 )
{
unsigned int V_14 , V_37 ;
for ( V_14 = F_4 ( V_38 ) ; V_14 > 0 ; V_14 -- ) {
* V_36 = V_38 [ V_14 - 1 ] ;
if ( F_12 ( V_34 , * V_36 , & V_37 ) < 0 )
continue;
if ( V_35 == V_37 )
break;
}
if ( V_14 == 0 )
return - V_39 ;
return 0 ;
}
static int F_13 ( struct V_33 * V_34 , unsigned int V_35 )
{
T_1 V_40 [ 2 ] ;
unsigned int V_36 ;
int V_12 ;
if ( F_11 ( V_34 , V_35 , & V_36 ) < 0 ) {
V_34 -> V_41 [ V_35 ] = 0 ;
V_34 -> V_42 [ V_35 ] = 0 ;
V_34 -> V_43 [ V_35 ] = 0 ;
V_34 -> V_44 [ V_35 ] = 0 ;
return 0 ;
}
V_12 = F_14 ( V_34 , V_36 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_15 ( V_34 , V_45 ,
V_40 , sizeof( V_40 ) ) ;
if ( V_12 < 0 )
return V_12 ;
V_34 -> V_41 [ V_35 ] = F_8 ( V_40 [ 0 ] ) ;
V_34 -> V_42 [ V_35 ] = F_8 ( V_40 [ 1 ] ) ;
V_12 = F_16 ( V_34 , V_46 ,
V_40 , sizeof( V_40 ) ) ;
if ( V_12 < 0 )
return V_12 ;
V_34 -> V_43 [ V_35 ] = F_8 ( V_40 [ 0 ] ) ;
V_34 -> V_44 [ V_35 ] = F_8 ( V_40 [ 1 ] ) ;
return 0 ;
}
static int F_17 ( struct V_33 * V_34 )
{
T_1 V_16 ;
int V_35 , V_12 ;
if ( V_34 -> V_47 > 0 ) {
V_12 = F_18 ( V_34 ,
V_48 ,
& V_16 , 4 ) ;
if ( V_12 < 0 )
return V_12 ;
V_34 -> V_47 = F_8 ( V_16 ) ;
} else {
V_34 -> V_47 = V_49 |
V_50 |
V_51 |
V_52 ;
}
for ( V_35 = 2 ; V_35 >= 0 ; -- V_35 ) {
V_12 = F_13 ( V_34 , V_35 ) ;
if ( V_12 < 0 )
return V_12 ;
}
return 0 ;
}
static void F_19 ( struct V_33 * V_34 )
{
struct V_53 * V_54 = V_34 -> V_54 ;
struct V_4 * V_55 = F_2 ( V_34 -> V_2 ) ;
char V_10 [ 32 ] , V_11 [ 32 ] ;
unsigned int V_14 ;
int V_12 ;
strcpy ( V_54 -> V_56 , L_2 ) ;
strcpy ( V_54 -> V_57 , L_2 ) ;
F_20 ( V_58 < sizeof( V_54 -> V_57 ) ) ;
V_12 = F_18 ( V_34 , V_59 ,
V_54 -> V_57 ,
sizeof( V_54 -> V_57 ) ) ;
if ( V_12 >= 0 ) {
F_20 ( sizeof( V_54 -> V_57 ) % 4 != 0 ) ;
for ( V_14 = 0 ; V_14 < sizeof( V_54 -> V_57 ) ; V_14 += 4 )
F_21 ( ( V_60 * ) & V_54 -> V_57 [ V_14 ] ) ;
V_54 -> V_57 [ sizeof( V_54 -> V_57 ) - 1 ] = '\0' ;
}
strcpy ( V_10 , L_3 ) ;
F_22 ( V_55 -> V_26 + 5 , V_61 , V_10 , sizeof( V_10 ) ) ;
strcpy ( V_11 , L_3 ) ;
F_22 ( V_34 -> V_2 -> V_20 , V_22 , V_11 , sizeof( V_11 ) ) ;
snprintf ( V_54 -> V_62 , sizeof( V_54 -> V_62 ) ,
L_4 ,
V_10 , V_11 , V_55 -> V_26 [ 4 ] & 0x3fffff ,
F_23 ( & V_34 -> V_2 -> V_5 ) , 100 << V_55 -> V_63 ) ;
strcpy ( V_54 -> V_64 , L_2 ) ;
}
static void F_24 ( struct V_53 * V_54 )
{
struct V_33 * V_34 = V_54 -> V_65 ;
F_25 ( V_34 ) ;
F_26 ( & V_34 -> V_66 ) ;
}
static int F_27 ( struct V_1 * V_2 , const struct V_67 * V_68 )
{
struct V_53 * V_54 ;
struct V_33 * V_34 ;
int V_12 ;
V_12 = F_1 ( V_2 ) ;
if ( V_12 < 0 )
goto V_28;
V_12 = F_28 ( & V_2 -> V_5 , - 1 , NULL , V_69 ,
sizeof( * V_34 ) , & V_54 ) ;
if ( V_12 < 0 )
goto V_28;
V_34 = V_54 -> V_65 ;
V_34 -> V_54 = V_54 ;
V_34 -> V_2 = V_2 ;
V_54 -> V_70 = F_24 ;
F_29 ( & V_34 -> V_71 ) ;
F_30 ( & V_34 -> V_66 ) ;
F_31 ( & V_34 -> V_72 ) ;
F_32 ( & V_34 -> V_73 ) ;
V_12 = F_33 ( V_34 ) ;
if ( V_12 < 0 )
goto error;
V_12 = F_17 ( V_34 ) ;
if ( V_12 < 0 )
goto error;
F_19 ( V_34 ) ;
V_12 = F_34 ( V_34 ) ;
if ( V_12 < 0 )
goto error;
V_12 = F_35 ( V_34 ) ;
if ( V_12 < 0 )
goto error;
F_36 ( V_34 ) ;
V_12 = F_37 ( V_34 ) ;
if ( V_12 < 0 )
goto error;
V_12 = F_38 ( V_34 ) ;
if ( V_12 < 0 )
goto error;
V_12 = F_39 ( V_54 ) ;
if ( V_12 < 0 ) {
F_40 ( V_34 ) ;
goto error;
}
F_41 ( & V_2 -> V_5 , V_34 ) ;
V_28:
return V_12 ;
error:
F_42 ( V_54 ) ;
return V_12 ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = F_44 ( & V_2 -> V_5 ) ;
F_45 ( V_34 -> V_54 ) ;
F_40 ( V_34 ) ;
F_46 ( V_34 -> V_54 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = F_44 ( & V_2 -> V_5 ) ;
F_48 ( V_34 ) ;
F_49 ( & V_34 -> V_66 ) ;
F_50 ( V_34 ) ;
F_51 ( & V_34 -> V_66 ) ;
}
static int T_2 F_52 ( void )
{
return F_53 ( & V_74 . V_56 ) ;
}
static void T_3 F_54 ( void )
{
F_55 ( & V_74 . V_56 ) ;
}
