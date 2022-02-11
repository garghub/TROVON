static int F_1 ( struct V_1 * V_1 , int V_2 , char * V_3 , int V_4 )
{
struct V_5 * V_6 = V_1 -> V_6 [ V_2 ] ;
struct V_7 V_8 [] = {
{
. V_9 = V_6 -> V_9 ,
. V_4 = V_4 ,
. V_3 = V_3
} ,
} ;
if ( ( F_2 ( V_6 -> V_10 , V_8 , 1 ) ) != 1 )
return - V_11 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_1 , int V_2 , char * V_3 , int V_4 )
{
struct V_5 * V_6 = V_1 -> V_6 [ V_2 ] ;
struct V_7 V_8 [] = {
{
. V_9 = V_6 -> V_9 ,
. V_12 = V_13 ,
. V_4 = V_4 ,
. V_3 = V_3
} ,
} ;
if ( ( F_2 ( V_6 -> V_10 , V_8 , 1 ) ) != 1 )
return - V_11 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_1 , char * V_14 )
{
char V_3 ;
int V_15 ;
unsigned V_16 = 0 ;
V_15 = F_3 ( V_1 , V_17 , V_14 , 1 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( * V_14 & V_18 )
F_5 ( 500 ) ;
else if ( ! ( * V_14 & V_19 ) )
return 0 ;
V_20:
* V_14 = V_21 ;
V_3 = V_22 | V_21 ;
V_15 = F_1 ( V_1 , V_17 , & V_3 , 1 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_3 ( V_1 , V_17 , & V_3 , 1 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( V_3 & ( V_18 | V_19 ) ) {
if ( V_16 < 5 ) {
++ V_16 ;
goto V_20;
} else
return - V_11 ;
}
return 1 ;
}
static int F_6 ( struct V_1 * V_1 )
{
char V_3 [ 1 ] ;
if ( F_3 ( V_1 , V_23 , V_3 , sizeof( V_3 ) ) < 0 )
return - V_11 ;
if ( ! ( V_3 [ 0 ] & V_24 ) )
return 0 ;
V_3 [ 0 ] &= ~ V_24 ;
return F_1 ( V_1 , V_23 , V_3 , sizeof( V_3 ) ) ;
}
static char F_7 ( struct V_1 * V_1 , int V_25 )
{
if ( V_1 -> V_26 )
return F_8 ( V_25 ) ;
if ( V_25 < 12 )
return F_8 ( V_25 ) ;
return 0x40 | F_8 ( V_25 - 12 ) ;
}
static int F_9 ( struct V_1 * V_1 , char V_2 )
{
unsigned V_25 ;
if ( V_1 -> V_26 )
return F_10 ( V_2 & 0x3f ) ;
V_25 = F_10 ( V_2 & 0x3f ) ;
if ( V_2 & 0x40 )
V_25 += 12 ;
return V_25 ;
}
static int F_11 ( struct V_5 * V_6 , struct V_27 * V_28 )
{
struct V_1 * V_1 = F_12 ( V_6 ) ;
int V_29 , V_30 ;
char V_3 [ 7 ] ;
F_13 ( & V_6 -> V_31 , L_1
L_2 , V_32 , V_28 -> V_33 ,
V_28 -> V_34 , V_28 -> V_35 , V_28 -> V_36 , V_28 -> V_37 , V_28 -> V_38 ,
V_28 -> V_39 ) ;
V_3 [ V_40 ] = F_8 ( V_28 -> V_38 - 100 ) ;
V_3 [ V_41 ] = F_8 ( V_28 -> V_37 + 1 ) ;
V_3 [ V_42 ] = F_8 ( V_28 -> V_36 ) ;
V_3 [ V_43 ] = F_8 ( V_28 -> V_39 ) ;
V_3 [ V_44 ] = F_7 ( V_1 , V_28 -> V_35 ) ;
V_3 [ V_45 ] = F_8 ( V_28 -> V_34 ) ;
V_3 [ V_46 ] = F_8 ( V_28 -> V_33 ) ;
for ( V_29 = 0 ; V_29 < 7 ; ++ V_29 )
V_3 [ V_29 ] = F_14 ( V_3 [ V_29 ] ) ;
V_30 = F_1 ( V_1 , V_47 , V_3 , sizeof( V_3 ) ) ;
return V_30 ;
}
static int F_15 ( struct V_5 * V_6 , struct V_27 * V_28 )
{
struct V_1 * V_1 = F_12 ( V_6 ) ;
char V_3 [ 7 ] ;
int V_29 , V_30 ;
V_30 = F_3 ( V_1 , V_47 , V_3 , sizeof( V_3 ) ) ;
if ( V_30 < 0 )
return V_30 ;
for ( V_29 = 0 ; V_29 < 7 ; ++ V_29 )
V_3 [ V_29 ] = F_14 ( V_3 [ V_29 ] ) ;
V_28 -> V_33 = F_10 ( V_3 [ V_46 ] ) ;
V_28 -> V_34 = F_10 ( V_3 [ V_45 ] ) ;
V_28 -> V_35 = F_9 ( V_1 , V_3 [ V_44 ] ) ;
V_28 -> V_39 = F_10 ( V_3 [ V_43 ] ) ;
V_28 -> V_36 = F_10 ( V_3 [ V_42 ] ) ;
V_28 -> V_37 = F_10 ( V_3 [ V_41 ] ) - 1 ;
V_28 -> V_38 = F_10 ( V_3 [ V_40 ] ) + 100 ;
F_13 ( & V_6 -> V_31 , L_3
L_2 , V_32 , V_28 -> V_33 ,
V_28 -> V_34 , V_28 -> V_35 , V_28 -> V_36 , V_28 -> V_37 , V_28 -> V_38 ,
V_28 -> V_39 ) ;
return F_16 ( V_28 ) ;
}
static int F_17 ( struct V_5 * V_6 , struct V_48 * V_49 )
{
struct V_1 * V_1 = F_12 ( V_6 ) ;
char V_3 [ 3 ] , V_50 = 0 ;
int V_30 , V_29 ;
F_13 ( & V_6 -> V_31 , L_4\
L_2 , V_32 , V_49 -> time . V_33 ,
V_49 -> time . V_34 , V_49 -> time . V_35 , V_49 -> time . V_36 ,
V_49 -> time . V_37 , V_49 -> time . V_38 , V_49 -> time . V_39 ) ;
V_30 = F_1 ( V_1 , V_23 , & V_50 , sizeof( V_50 ) ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_3 ( V_1 , V_17 , & V_50 , sizeof( V_50 ) ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_49 -> V_51 )
V_50 = V_52 ;
else
V_50 = V_53 ;
V_50 = F_14 ( V_50 ) ;
V_30 = F_1 ( V_1 , V_23 , & V_50 , sizeof( V_50 ) ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_49 -> time . V_39 != - 1 )
V_3 [ V_54 ] = F_8 ( V_49 -> time . V_39 ) | 0x80 ;
else
V_3 [ V_54 ] = 0 ;
V_3 [ V_55 ] = F_7 ( V_1 ,
V_49 -> time . V_35 ) | 0x80 ;
V_3 [ V_56 ] = F_8 ( V_49 -> time . V_34 ) | 0x80 ;
if ( V_49 -> time . V_35 >= 12 )
V_3 [ V_55 ] |= 0x40 ;
for ( V_29 = 0 ; V_29 < 3 ; ++ V_29 )
V_3 [ V_29 ] = F_14 ( V_3 [ V_29 ] ) ;
V_30 = F_1 ( V_1 , V_57 , V_3 ,
sizeof( V_3 ) ) ;
return V_30 ;
}
static int F_18 ( struct V_5 * V_6 , struct V_48 * V_49 )
{
struct V_1 * V_1 = F_12 ( V_6 ) ;
char V_3 [ 3 ] , V_50 ;
int V_29 , V_30 ;
V_30 = F_3 ( V_1 , V_23 , & V_50 , sizeof( V_50 ) ) ;
if ( V_30 < 0 )
return V_30 ;
if ( ( F_14 ( V_50 ) & V_58 ) != V_52 ) {
V_49 -> V_51 = 0 ;
return 0 ;
} else {
V_49 -> V_51 = 1 ;
}
V_30 = F_3 ( V_1 , V_57 , V_3 , sizeof( V_3 ) ) ;
if ( V_30 < 0 )
return V_30 ;
for ( V_29 = 0 ; V_29 < 3 ; ++ V_29 )
V_3 [ V_29 ] = F_14 ( V_3 [ V_29 ] ) ;
if ( V_3 [ V_54 ] & 0x80 )
V_49 -> time . V_39 =
F_10 ( V_3 [ V_54 ] & ~ 0x80 ) ;
if ( V_3 [ V_55 ] & 0x80 )
V_49 -> time . V_35 =
F_9 ( V_1 ,
V_3 [ V_55 ] & ~ 0x80 ) ;
if ( V_3 [ V_56 ] & 0x80 )
V_49 -> time . V_34 = F_10 ( V_3 [ V_56 ] & ~ 0x80 ) ;
V_49 -> time . V_33 = 0 ;
F_13 ( & V_6 -> V_31 , L_5 ,
V_32 , V_49 -> time . V_34 , V_49 -> time . V_35 ,
V_49 -> time . V_39 ) ;
return 0 ;
}
static int F_19 ( struct V_59 * V_31 , struct V_48 * V_49 )
{
return F_18 ( F_20 ( V_31 ) , V_49 ) ;
}
static int F_21 ( struct V_59 * V_31 , struct V_48 * V_49 )
{
return F_17 ( F_20 ( V_31 ) , V_49 ) ;
}
static int F_22 ( struct V_59 * V_31 , struct V_27 * V_28 )
{
return F_15 ( F_20 ( V_31 ) , V_28 ) ;
}
static int F_23 ( struct V_59 * V_31 , struct V_27 * V_28 )
{
return F_11 ( F_20 ( V_31 ) , V_28 ) ;
}
static int F_24 ( struct V_5 * V_6 ,
const struct V_60 * V_61 )
{
int V_30 , V_62 ;
unsigned int V_29 ;
struct V_1 * V_1 ;
struct V_27 V_28 ;
char V_3 , V_14 ;
if ( ! F_25 ( V_6 -> V_10 , V_63 ) ) {
V_30 = - V_64 ;
goto exit;
}
V_1 = F_26 ( & V_6 -> V_31 , sizeof( struct V_1 ) ,
V_65 ) ;
if ( ! V_1 ) {
V_30 = - V_66 ;
goto exit;
}
V_1 -> V_6 [ 0 ] = V_6 ;
F_27 ( V_6 , V_1 ) ;
for ( V_29 = 1 ; V_29 < 8 ; ++ V_29 ) {
V_1 -> V_6 [ V_29 ] = F_28 ( V_6 -> V_10 ,
V_6 -> V_9 + V_29 ) ;
if ( ! V_1 -> V_6 [ V_29 ] ) {
F_29 ( & V_6 -> V_31 , L_6 ,
V_6 -> V_9 + V_29 ) ;
V_30 = - V_67 ;
goto V_68;
}
}
V_62 = F_4 ( V_1 , & V_14 ) ;
if ( V_62 < 0 ) {
V_30 = V_62 ;
F_29 ( & V_6 -> V_31 , L_7 ) ;
goto V_68;
}
if ( V_14 & V_21 )
V_1 -> V_26 = 1 ;
else
V_1 -> V_26 = 0 ;
if ( V_14 & V_69 ) {
V_3 = 0 ;
V_30 = F_1 ( V_1 , V_23 , & V_3 , 1 ) ;
if ( V_30 < 0 ) {
F_29 ( & V_6 -> V_31 , L_8 ) ;
goto V_68;
}
} else {
V_30 = F_6 ( V_1 ) ;
if ( V_30 < 0 ) {
F_29 ( & V_6 -> V_31 , L_9 ) ;
goto V_68;
}
}
if ( V_62 > 0 || F_15 ( V_6 , & V_28 ) < 0 )
F_30 ( & V_6 -> V_31 , L_10 ) ;
F_31 ( & V_6 -> V_31 , 1 ) ;
V_1 -> V_70 = F_32 ( & V_6 -> V_31 ,
V_71 . V_72 . V_73 ,
& V_74 , V_75 ) ;
if ( F_33 ( V_1 -> V_70 ) ) {
V_30 = F_34 ( V_1 -> V_70 ) ;
goto V_68;
}
if ( V_14 & V_69 )
F_35 ( V_1 -> V_70 , 1 , V_76 ) ;
return 0 ;
V_68:
for ( V_29 = 1 ; V_29 < 8 ; ++ V_29 )
if ( V_1 -> V_6 [ V_29 ] )
F_36 ( V_1 -> V_6 [ V_29 ] ) ;
exit:
return V_30 ;
}
static int F_37 ( struct V_5 * V_6 )
{
unsigned int V_29 ;
struct V_1 * V_1 = F_12 ( V_6 ) ;
for ( V_29 = 1 ; V_29 < 8 ; ++ V_29 )
if ( V_1 -> V_6 [ V_29 ] )
F_36 ( V_1 -> V_6 [ V_29 ] ) ;
return 0 ;
}
