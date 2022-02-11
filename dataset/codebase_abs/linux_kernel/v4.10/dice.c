static bool F_1 ( struct V_1 * V_2 )
{
const char * const V_3 [] = {
L_1 ,
L_2 ,
L_3 ,
L_4 ,
} ;
char V_4 [ 32 ] ;
unsigned int V_5 ;
int V_6 ;
V_6 = F_2 ( V_2 -> V_7 , V_8 , V_4 , sizeof( V_4 ) ) ;
if ( V_6 < 0 )
return false ;
for ( V_5 = 0 ; V_5 < F_3 ( V_3 ) ; V_5 ++ ) {
if ( strcmp ( V_3 [ V_5 ] , V_4 ) == 0 )
break;
}
return V_5 < F_3 ( V_3 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_5 ( V_2 ) ;
struct V_11 V_12 ;
int V_13 , V_14 , V_15 = - 1 , V_4 = - 1 ;
unsigned int V_16 ;
F_6 ( & V_12 , V_2 -> V_7 ) ;
while ( F_7 ( & V_12 , & V_13 , & V_14 ) ) {
switch ( V_13 ) {
case V_17 :
V_15 = V_14 ;
break;
case V_8 :
V_4 = V_14 ;
break;
}
}
if ( V_15 == V_18 || V_15 == V_19 ) {
if ( F_1 ( V_2 ) )
return 0 ;
}
if ( V_15 == V_20 )
V_16 = V_21 ;
else if ( V_15 == V_22 )
V_16 = V_23 ;
else
V_16 = V_24 ;
if ( V_10 -> V_25 [ 3 ] != ( ( V_15 << 8 ) | V_16 ) ||
V_10 -> V_25 [ 4 ] >> 22 != V_4 )
return - V_26 ;
return 0 ;
}
static int F_8 ( struct V_27 * V_28 )
{
T_1 V_29 ;
int V_6 ;
if ( V_28 -> V_30 > 0 ) {
V_6 = F_9 ( V_28 ,
V_31 ,
& V_29 , 4 ) ;
if ( V_6 < 0 )
return V_6 ;
V_28 -> V_30 = F_10 ( V_29 ) ;
} else {
V_28 -> V_30 = V_32 |
V_33 |
V_34 |
V_35 ;
}
return 0 ;
}
static void F_11 ( struct V_27 * V_28 )
{
struct V_36 * V_37 = V_28 -> V_37 ;
struct V_9 * V_38 = F_5 ( V_28 -> V_2 ) ;
char V_15 [ 32 ] , V_4 [ 32 ] ;
unsigned int V_5 ;
int V_6 ;
strcpy ( V_37 -> V_39 , L_5 ) ;
strcpy ( V_37 -> V_40 , L_5 ) ;
F_12 ( V_41 < sizeof( V_37 -> V_40 ) ) ;
V_6 = F_9 ( V_28 , V_42 ,
V_37 -> V_40 ,
sizeof( V_37 -> V_40 ) ) ;
if ( V_6 >= 0 ) {
F_12 ( sizeof( V_37 -> V_40 ) % 4 != 0 ) ;
for ( V_5 = 0 ; V_5 < sizeof( V_37 -> V_40 ) ; V_5 += 4 )
F_13 ( ( V_43 * ) & V_37 -> V_40 [ V_5 ] ) ;
V_37 -> V_40 [ sizeof( V_37 -> V_40 ) - 1 ] = '\0' ;
}
strcpy ( V_15 , L_6 ) ;
F_2 ( V_38 -> V_25 + 5 , V_44 , V_15 , sizeof( V_15 ) ) ;
strcpy ( V_4 , L_6 ) ;
F_2 ( V_28 -> V_2 -> V_7 , V_8 , V_4 , sizeof( V_4 ) ) ;
snprintf ( V_37 -> V_45 , sizeof( V_37 -> V_45 ) ,
L_7 ,
V_15 , V_4 , V_38 -> V_25 [ 4 ] & 0x3fffff ,
F_14 ( & V_28 -> V_2 -> V_10 ) , 100 << V_38 -> V_46 ) ;
strcpy ( V_37 -> V_47 , L_5 ) ;
}
static void F_15 ( struct V_27 * V_28 )
{
F_16 ( V_28 ) ;
F_17 ( V_28 ) ;
F_18 ( V_28 -> V_2 ) ;
F_19 ( & V_28 -> V_48 ) ;
F_20 ( V_28 ) ;
}
static void F_21 ( struct V_36 * V_37 )
{
F_15 ( V_37 -> V_49 ) ;
}
static void F_22 ( struct V_50 * V_51 )
{
struct V_27 * V_28 = F_23 ( V_51 , struct V_27 , V_52 . V_51 ) ;
int V_6 ;
if ( V_28 -> V_53 )
return;
V_6 = F_24 ( & V_28 -> V_2 -> V_10 , - 1 , NULL , V_54 , 0 ,
& V_28 -> V_37 ) ;
if ( V_6 < 0 )
return;
if ( F_1 ( V_28 -> V_2 ) )
V_28 -> V_55 = true ;
V_6 = F_25 ( V_28 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_8 ( V_28 ) ;
if ( V_6 < 0 )
goto error;
F_11 ( V_28 ) ;
V_6 = F_26 ( V_28 ) ;
if ( V_6 < 0 )
goto error;
F_27 ( V_28 ) ;
V_6 = F_28 ( V_28 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_29 ( V_28 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_30 ( V_28 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_31 ( V_28 -> V_37 ) ;
if ( V_6 < 0 )
goto error;
V_28 -> V_37 -> V_56 = F_21 ;
V_28 -> V_37 -> V_49 = V_28 ;
V_28 -> V_53 = true ;
return;
error:
F_16 ( V_28 ) ;
F_17 ( V_28 ) ;
F_16 ( V_28 ) ;
F_32 ( V_28 -> V_37 ) ;
F_33 ( & V_28 -> V_2 -> V_10 ,
L_8 , V_6 ) ;
}
static int F_34 ( struct V_1 * V_2 , const struct V_57 * V_58 )
{
struct V_27 * V_28 ;
int V_6 ;
V_6 = F_4 ( V_2 ) ;
if ( V_6 < 0 )
return - V_26 ;
V_28 = F_35 ( sizeof( struct V_27 ) , V_59 ) ;
if ( V_28 == NULL )
return - V_60 ;
V_28 -> V_2 = F_36 ( V_2 ) ;
F_37 ( & V_2 -> V_10 , V_28 ) ;
F_38 ( & V_28 -> V_61 ) ;
F_39 ( & V_28 -> V_48 ) ;
F_40 ( & V_28 -> V_62 ) ;
F_41 ( & V_28 -> V_63 ) ;
F_42 ( & V_28 -> V_52 , F_22 ) ;
F_43 ( V_2 , & V_28 -> V_52 ) ;
return 0 ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = F_45 ( & V_2 -> V_10 ) ;
F_46 ( & V_28 -> V_52 ) ;
if ( V_28 -> V_53 ) {
F_47 ( V_28 -> V_37 ) ;
} else {
F_15 ( V_28 ) ;
}
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = F_45 ( & V_2 -> V_10 ) ;
if ( ! V_28 -> V_53 )
F_43 ( V_2 , & V_28 -> V_52 ) ;
F_49 ( V_28 ) ;
if ( V_28 -> V_53 ) {
F_50 ( & V_28 -> V_48 ) ;
F_51 ( V_28 ) ;
F_52 ( & V_28 -> V_48 ) ;
}
}
static int T_2 F_53 ( void )
{
return F_54 ( & V_64 . V_39 ) ;
}
static void T_3 F_55 ( void )
{
F_56 ( & V_64 . V_39 ) ;
}
