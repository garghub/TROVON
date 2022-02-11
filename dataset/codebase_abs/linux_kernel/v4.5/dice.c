static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 V_6 ;
int V_7 , V_8 , V_9 = - 1 , V_10 = - 1 ;
unsigned int V_11 ;
F_3 ( & V_6 , V_2 -> V_12 ) ;
while ( F_4 ( & V_6 , & V_7 , & V_8 ) ) {
switch ( V_7 ) {
case V_13 :
V_9 = V_8 ;
break;
case V_14 :
V_10 = V_8 ;
break;
}
}
if ( V_9 == V_15 )
V_11 = V_16 ;
else if ( V_9 == V_17 )
V_11 = V_18 ;
else
V_11 = V_19 ;
if ( V_4 -> V_20 [ 3 ] != ( ( V_9 << 8 ) | V_11 ) ||
V_4 -> V_20 [ 4 ] >> 22 != V_10 )
return - V_21 ;
return 0 ;
}
static int F_5 ( struct V_22 * V_23 ,
unsigned int V_24 , unsigned int * V_25 )
{
unsigned int V_26 , V_27 ;
for ( V_26 = F_6 ( V_28 ) ; V_26 > 0 ; V_26 -- ) {
* V_25 = V_28 [ V_26 - 1 ] ;
if ( F_7 ( V_23 , * V_25 , & V_27 ) < 0 )
continue;
if ( V_24 == V_27 )
break;
}
if ( V_26 == 0 )
return - V_29 ;
return 0 ;
}
static int F_8 ( struct V_22 * V_23 , unsigned int V_24 )
{
T_1 V_30 [ 2 ] ;
unsigned int V_25 ;
int V_31 ;
if ( F_5 ( V_23 , V_24 , & V_25 ) < 0 ) {
V_23 -> V_32 [ V_24 ] = 0 ;
V_23 -> V_33 [ V_24 ] = 0 ;
V_23 -> V_34 [ V_24 ] = 0 ;
V_23 -> V_35 [ V_24 ] = 0 ;
return 0 ;
}
V_31 = F_9 ( V_23 , V_25 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_10 ( V_23 , V_36 ,
V_30 , sizeof( V_30 ) ) ;
if ( V_31 < 0 )
return V_31 ;
V_23 -> V_32 [ V_24 ] = F_11 ( V_30 [ 0 ] ) ;
V_23 -> V_33 [ V_24 ] = F_11 ( V_30 [ 1 ] ) ;
V_31 = F_12 ( V_23 , V_37 ,
V_30 , sizeof( V_30 ) ) ;
if ( V_31 < 0 )
return V_31 ;
V_23 -> V_34 [ V_24 ] = F_11 ( V_30 [ 0 ] ) ;
V_23 -> V_35 [ V_24 ] = F_11 ( V_30 [ 1 ] ) ;
return 0 ;
}
static int F_13 ( struct V_22 * V_23 )
{
T_1 V_38 ;
int V_24 , V_31 ;
if ( V_23 -> V_39 > 0 ) {
V_31 = F_14 ( V_23 ,
V_40 ,
& V_38 , 4 ) ;
if ( V_31 < 0 )
return V_31 ;
V_23 -> V_39 = F_11 ( V_38 ) ;
} else {
V_23 -> V_39 = V_41 |
V_42 |
V_43 |
V_44 ;
}
for ( V_24 = 2 ; V_24 >= 0 ; -- V_24 ) {
V_31 = F_8 ( V_23 , V_24 ) ;
if ( V_31 < 0 )
return V_31 ;
}
return 0 ;
}
static void F_15 ( struct V_22 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_46 ;
struct V_3 * V_47 = F_2 ( V_23 -> V_2 ) ;
char V_9 [ 32 ] , V_10 [ 32 ] ;
unsigned int V_26 ;
int V_31 ;
strcpy ( V_46 -> V_48 , L_1 ) ;
strcpy ( V_46 -> V_49 , L_1 ) ;
F_16 ( V_50 < sizeof( V_46 -> V_49 ) ) ;
V_31 = F_14 ( V_23 , V_51 ,
V_46 -> V_49 ,
sizeof( V_46 -> V_49 ) ) ;
if ( V_31 >= 0 ) {
F_16 ( sizeof( V_46 -> V_49 ) % 4 != 0 ) ;
for ( V_26 = 0 ; V_26 < sizeof( V_46 -> V_49 ) ; V_26 += 4 )
F_17 ( ( V_52 * ) & V_46 -> V_49 [ V_26 ] ) ;
V_46 -> V_49 [ sizeof( V_46 -> V_49 ) - 1 ] = '\0' ;
}
strcpy ( V_9 , L_2 ) ;
F_18 ( V_47 -> V_20 + 5 , V_53 , V_9 , sizeof( V_9 ) ) ;
strcpy ( V_10 , L_2 ) ;
F_18 ( V_23 -> V_2 -> V_12 , V_14 , V_10 , sizeof( V_10 ) ) ;
snprintf ( V_46 -> V_54 , sizeof( V_46 -> V_54 ) ,
L_3 ,
V_9 , V_10 , V_47 -> V_20 [ 4 ] & 0x3fffff ,
F_19 ( & V_23 -> V_2 -> V_4 ) , 100 << V_47 -> V_55 ) ;
strcpy ( V_46 -> V_56 , L_1 ) ;
}
static void F_20 ( struct V_22 * V_23 )
{
F_21 ( V_23 ) ;
F_22 ( V_23 ) ;
F_23 ( V_23 -> V_2 ) ;
F_24 ( & V_23 -> V_57 ) ;
F_25 ( V_23 ) ;
}
static void F_26 ( struct V_45 * V_46 )
{
F_20 ( V_46 -> V_58 ) ;
}
static void F_27 ( struct V_59 * V_60 )
{
struct V_22 * V_23 = F_28 ( V_60 , struct V_22 , V_61 . V_60 ) ;
int V_31 ;
if ( V_23 -> V_62 )
return;
V_31 = F_29 ( & V_23 -> V_2 -> V_4 , - 1 , NULL , V_63 , 0 ,
& V_23 -> V_46 ) ;
if ( V_31 < 0 )
return;
V_31 = F_30 ( V_23 ) ;
if ( V_31 < 0 )
goto error;
V_31 = F_13 ( V_23 ) ;
if ( V_31 < 0 )
goto error;
F_15 ( V_23 ) ;
F_31 ( V_23 ) ;
V_31 = F_32 ( V_23 ) ;
if ( V_31 < 0 )
goto error;
V_31 = F_33 ( V_23 ) ;
if ( V_31 < 0 )
goto error;
V_31 = F_34 ( V_23 ) ;
if ( V_31 < 0 )
goto error;
V_31 = F_35 ( V_23 -> V_46 ) ;
if ( V_31 < 0 )
goto error;
V_23 -> V_46 -> V_64 = F_26 ;
V_23 -> V_46 -> V_58 = V_23 ;
V_23 -> V_62 = true ;
return;
error:
F_22 ( V_23 ) ;
F_36 ( V_23 -> V_46 ) ;
F_37 ( & V_23 -> V_2 -> V_4 ,
L_4 , V_31 ) ;
}
static void F_38 ( struct V_22 * V_23 )
{
struct V_65 * V_65 = F_2 ( V_23 -> V_2 ) -> V_46 ;
T_2 V_66 , V_67 ;
V_66 = F_39 () ;
V_67 = V_65 -> V_68 + F_40 ( V_69 ) ;
if ( F_41 ( V_67 , V_66 ) )
V_67 -= V_66 ;
else
V_67 = 0 ;
F_42 ( V_70 , & V_23 -> V_61 , V_67 ) ;
}
static int F_43 ( struct V_1 * V_2 , const struct V_71 * V_72 )
{
struct V_22 * V_23 ;
int V_31 ;
V_31 = F_1 ( V_2 ) ;
if ( V_31 < 0 )
return - V_21 ;
V_23 = F_44 ( sizeof( struct V_22 ) , V_73 ) ;
if ( V_23 == NULL )
return - V_74 ;
V_23 -> V_2 = F_45 ( V_2 ) ;
F_46 ( & V_2 -> V_4 , V_23 ) ;
F_47 ( & V_23 -> V_75 ) ;
F_48 ( & V_23 -> V_57 ) ;
F_49 ( & V_23 -> V_76 ) ;
F_50 ( & V_23 -> V_77 ) ;
V_31 = F_51 ( V_23 ) ;
if ( V_31 < 0 ) {
F_20 ( V_23 ) ;
return V_31 ;
}
F_52 ( & V_23 -> V_61 , F_27 ) ;
F_38 ( V_23 ) ;
return 0 ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_54 ( & V_2 -> V_4 ) ;
F_55 ( & V_23 -> V_61 ) ;
if ( V_23 -> V_62 ) {
F_56 ( V_23 -> V_46 ) ;
} else {
F_20 ( V_23 ) ;
}
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_54 ( & V_2 -> V_4 ) ;
if ( ! V_23 -> V_62 )
F_38 ( V_23 ) ;
F_58 ( V_23 ) ;
if ( V_23 -> V_62 ) {
F_59 ( & V_23 -> V_57 ) ;
F_60 ( V_23 ) ;
F_61 ( & V_23 -> V_57 ) ;
}
}
static int T_3 F_62 ( void )
{
return F_63 ( & V_78 . V_48 ) ;
}
static void T_4 F_64 ( void )
{
F_65 ( & V_78 . V_48 ) ;
}
