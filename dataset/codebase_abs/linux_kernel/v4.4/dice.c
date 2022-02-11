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
T_1 * V_15 ;
T_2 V_16 ;
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
else if ( V_10 == V_25 )
V_13 = V_26 ;
else
V_13 = V_27 ;
if ( V_5 -> V_28 [ 3 ] != ( ( V_10 << 8 ) | V_13 ) ||
V_5 -> V_28 [ 4 ] >> 22 != V_11 ) {
V_12 = - V_29 ;
goto V_30;
}
V_12 = F_7 ( V_2 , V_31 ,
V_32 , V_15 ,
sizeof( T_1 ) * F_4 ( V_3 ) , 0 ) ;
if ( V_12 < 0 ) {
V_12 = - V_29 ;
goto V_30;
}
for ( V_14 = 0 ; V_14 < F_4 ( V_3 ) ; ++ V_14 ) {
V_16 = F_8 ( V_15 [ V_14 ] ) ;
if ( V_16 < V_3 [ V_14 ] || V_16 >= 0x40000 ) {
V_12 = - V_29 ;
goto V_30;
}
}
V_12 = F_7 ( V_2 , V_33 ,
V_32 +
F_8 ( V_15 [ 0 ] ) * 4 + V_34 ,
& V_17 , 4 , 0 ) ;
if ( V_12 < 0 ) {
V_12 = - V_29 ;
goto V_30;
}
if ( ( V_17 & F_9 ( 0xff000000 ) ) != F_9 ( 0x01000000 ) ) {
F_10 ( & V_2 -> V_5 ,
L_1 , F_8 ( V_17 ) ) ;
V_12 = - V_29 ;
goto V_30;
}
V_30:
return V_12 ;
}
static int F_11 ( struct V_35 * V_36 ,
unsigned int V_37 , unsigned int * V_38 )
{
unsigned int V_14 , V_39 ;
for ( V_14 = F_4 ( V_40 ) ; V_14 > 0 ; V_14 -- ) {
* V_38 = V_40 [ V_14 - 1 ] ;
if ( F_12 ( V_36 , * V_38 , & V_39 ) < 0 )
continue;
if ( V_37 == V_39 )
break;
}
if ( V_14 == 0 )
return - V_41 ;
return 0 ;
}
static int F_13 ( struct V_35 * V_36 , unsigned int V_37 )
{
T_1 V_42 [ 2 ] ;
unsigned int V_38 ;
int V_12 ;
if ( F_11 ( V_36 , V_37 , & V_38 ) < 0 ) {
V_36 -> V_43 [ V_37 ] = 0 ;
V_36 -> V_44 [ V_37 ] = 0 ;
V_36 -> V_45 [ V_37 ] = 0 ;
V_36 -> V_46 [ V_37 ] = 0 ;
return 0 ;
}
V_12 = F_14 ( V_36 , V_38 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_15 ( V_36 , V_47 ,
V_42 , sizeof( V_42 ) ) ;
if ( V_12 < 0 )
return V_12 ;
V_36 -> V_43 [ V_37 ] = F_8 ( V_42 [ 0 ] ) ;
V_36 -> V_44 [ V_37 ] = F_8 ( V_42 [ 1 ] ) ;
V_12 = F_16 ( V_36 , V_48 ,
V_42 , sizeof( V_42 ) ) ;
if ( V_12 < 0 )
return V_12 ;
V_36 -> V_45 [ V_37 ] = F_8 ( V_42 [ 0 ] ) ;
V_36 -> V_46 [ V_37 ] = F_8 ( V_42 [ 1 ] ) ;
return 0 ;
}
static int F_17 ( struct V_35 * V_36 )
{
T_1 V_16 ;
int V_37 , V_12 ;
if ( V_36 -> V_49 > 0 ) {
V_12 = F_18 ( V_36 ,
V_50 ,
& V_16 , 4 ) ;
if ( V_12 < 0 )
return V_12 ;
V_36 -> V_49 = F_8 ( V_16 ) ;
} else {
V_36 -> V_49 = V_51 |
V_52 |
V_53 |
V_54 ;
}
for ( V_37 = 2 ; V_37 >= 0 ; -- V_37 ) {
V_12 = F_13 ( V_36 , V_37 ) ;
if ( V_12 < 0 )
return V_12 ;
}
return 0 ;
}
static void F_19 ( struct V_35 * V_36 )
{
struct V_55 * V_56 = V_36 -> V_56 ;
struct V_4 * V_57 = F_2 ( V_36 -> V_2 ) ;
char V_10 [ 32 ] , V_11 [ 32 ] ;
unsigned int V_14 ;
int V_12 ;
strcpy ( V_56 -> V_58 , L_2 ) ;
strcpy ( V_56 -> V_59 , L_2 ) ;
F_20 ( V_60 < sizeof( V_56 -> V_59 ) ) ;
V_12 = F_18 ( V_36 , V_61 ,
V_56 -> V_59 ,
sizeof( V_56 -> V_59 ) ) ;
if ( V_12 >= 0 ) {
F_20 ( sizeof( V_56 -> V_59 ) % 4 != 0 ) ;
for ( V_14 = 0 ; V_14 < sizeof( V_56 -> V_59 ) ; V_14 += 4 )
F_21 ( ( T_2 * ) & V_56 -> V_59 [ V_14 ] ) ;
V_56 -> V_59 [ sizeof( V_56 -> V_59 ) - 1 ] = '\0' ;
}
strcpy ( V_10 , L_3 ) ;
F_22 ( V_57 -> V_28 + 5 , V_62 , V_10 , sizeof( V_10 ) ) ;
strcpy ( V_11 , L_3 ) ;
F_22 ( V_36 -> V_2 -> V_20 , V_22 , V_11 , sizeof( V_11 ) ) ;
snprintf ( V_56 -> V_63 , sizeof( V_56 -> V_63 ) ,
L_4 ,
V_10 , V_11 , V_57 -> V_28 [ 4 ] & 0x3fffff ,
F_23 ( & V_36 -> V_2 -> V_5 ) , 100 << V_57 -> V_64 ) ;
strcpy ( V_56 -> V_65 , L_2 ) ;
}
static void F_24 ( struct V_55 * V_56 )
{
struct V_35 * V_36 = V_56 -> V_66 ;
F_25 ( V_36 ) ;
F_26 ( V_36 ) ;
F_27 ( V_36 -> V_2 ) ;
F_28 ( & V_36 -> V_67 ) ;
}
static int F_29 ( struct V_1 * V_2 , const struct V_68 * V_69 )
{
struct V_55 * V_56 ;
struct V_35 * V_36 ;
int V_12 ;
V_12 = F_1 ( V_2 ) ;
if ( V_12 < 0 )
goto V_30;
V_12 = F_30 ( & V_2 -> V_5 , - 1 , NULL , V_70 ,
sizeof( * V_36 ) , & V_56 ) ;
if ( V_12 < 0 )
goto V_30;
V_36 = V_56 -> V_66 ;
V_36 -> V_56 = V_56 ;
V_36 -> V_2 = F_31 ( V_2 ) ;
V_56 -> V_71 = F_24 ;
F_32 ( & V_36 -> V_72 ) ;
F_33 ( & V_36 -> V_67 ) ;
F_34 ( & V_36 -> V_73 ) ;
F_35 ( & V_36 -> V_74 ) ;
V_12 = F_36 ( V_36 ) ;
if ( V_12 < 0 )
goto error;
V_12 = F_17 ( V_36 ) ;
if ( V_12 < 0 )
goto error;
F_19 ( V_36 ) ;
V_12 = F_37 ( V_36 ) ;
if ( V_12 < 0 )
goto error;
V_12 = F_38 ( V_36 ) ;
if ( V_12 < 0 )
goto error;
F_39 ( V_36 ) ;
V_12 = F_40 ( V_36 ) ;
if ( V_12 < 0 )
goto error;
V_12 = F_41 ( V_36 ) ;
if ( V_12 < 0 )
goto error;
V_12 = F_42 ( V_56 ) ;
if ( V_12 < 0 ) {
F_25 ( V_36 ) ;
goto error;
}
F_43 ( & V_2 -> V_5 , V_36 ) ;
V_30:
return V_12 ;
error:
F_44 ( V_56 ) ;
return V_12 ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = F_46 ( & V_2 -> V_5 ) ;
F_47 ( V_36 -> V_56 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = F_46 ( & V_2 -> V_5 ) ;
F_49 ( V_36 ) ;
F_50 ( & V_36 -> V_67 ) ;
F_51 ( V_36 ) ;
F_52 ( & V_36 -> V_67 ) ;
}
static int T_3 F_53 ( void )
{
return F_54 ( & V_75 . V_58 ) ;
}
static void T_4 F_55 ( void )
{
F_56 ( & V_75 . V_58 ) ;
}
