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
static int F_4 ( struct V_1 * V_1 )
{
char V_3 ;
int V_14 ;
unsigned V_15 = 0 ;
V_16:
V_3 = V_17 | V_18 ;
V_14 = F_1 ( V_1 , V_19 , & V_3 , 1 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_3 ( V_1 , V_19 , & V_3 , 1 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_3 & ( V_20 | V_21 ) ) {
if ( V_15 < 5 ) {
++ V_15 ;
goto V_16;
} else
return - V_11 ;
}
return 1 ;
}
static int F_5 ( struct V_1 * V_1 , char * V_22 )
{
int V_14 ;
V_14 = F_3 ( V_1 , V_19 , V_22 , 1 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( * V_22 & V_20 ) {
F_6 ( 500 ) ;
return 1 ;
} else if ( * V_22 & V_21 )
return 1 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_1 )
{
char V_3 [ 1 ] ;
if ( F_3 ( V_1 , V_23 , V_3 , sizeof( V_3 ) ) < 0 )
return - V_11 ;
if ( ! ( V_3 [ 0 ] & V_24 ) )
return 0 ;
V_3 [ 0 ] &= ~ V_24 ;
return F_1 ( V_1 , V_23 , V_3 , sizeof( V_3 ) ) ;
}
static char F_8 ( struct V_1 * V_1 , int V_25 )
{
if ( V_1 -> V_26 )
return F_9 ( V_25 ) ;
if ( V_25 < 12 )
return F_9 ( V_25 ) ;
return 0x40 | F_9 ( V_25 - 12 ) ;
}
static int F_10 ( struct V_1 * V_1 , char V_2 )
{
unsigned V_25 ;
if ( V_1 -> V_26 )
return F_11 ( V_2 & 0x3f ) ;
V_25 = F_11 ( V_2 & 0x3f ) ;
if ( V_2 & 0x40 )
V_25 += 12 ;
return V_25 ;
}
static int F_12 ( struct V_5 * V_6 , struct V_27 * V_28 )
{
struct V_1 * V_1 = F_13 ( V_6 ) ;
int V_29 , V_30 ;
char V_3 [ 7 ] , V_31 ;
F_14 ( & V_6 -> V_32 , L_1
L_2 , V_33 , V_28 -> V_34 ,
V_28 -> V_35 , V_28 -> V_36 , V_28 -> V_37 , V_28 -> V_38 , V_28 -> V_39 ,
V_28 -> V_40 ) ;
if ( F_5 ( V_1 , & V_31 ) == 1 )
F_4 ( V_1 ) ;
V_3 [ V_41 ] = F_9 ( V_28 -> V_39 - 100 ) ;
V_3 [ V_42 ] = F_9 ( V_28 -> V_38 + 1 ) ;
V_3 [ V_43 ] = F_9 ( V_28 -> V_37 ) ;
V_3 [ V_44 ] = F_9 ( V_28 -> V_40 ) ;
V_3 [ V_45 ] = F_8 ( V_1 , V_28 -> V_36 ) ;
V_3 [ V_46 ] = F_9 ( V_28 -> V_35 ) ;
V_3 [ V_47 ] = F_9 ( V_28 -> V_34 ) ;
for ( V_29 = 0 ; V_29 < 7 ; ++ V_29 )
V_3 [ V_29 ] = F_15 ( V_3 [ V_29 ] ) ;
V_30 = F_1 ( V_1 , V_48 , V_3 , sizeof( V_3 ) ) ;
return V_30 ;
}
static int F_16 ( struct V_5 * V_6 , struct V_27 * V_28 )
{
struct V_1 * V_1 = F_13 ( V_6 ) ;
char V_3 [ 7 ] , V_31 ;
int V_29 , V_30 ;
if ( F_5 ( V_1 , & V_31 ) == 1 )
return - V_49 ;
V_30 = F_3 ( V_1 , V_48 , V_3 , sizeof( V_3 ) ) ;
if ( V_30 < 0 )
return V_30 ;
for ( V_29 = 0 ; V_29 < 7 ; ++ V_29 )
V_3 [ V_29 ] = F_15 ( V_3 [ V_29 ] ) ;
V_28 -> V_34 = F_11 ( V_3 [ V_47 ] ) ;
V_28 -> V_35 = F_11 ( V_3 [ V_46 ] ) ;
V_28 -> V_36 = F_10 ( V_1 , V_3 [ V_45 ] ) ;
V_28 -> V_40 = F_11 ( V_3 [ V_44 ] ) ;
V_28 -> V_37 = F_11 ( V_3 [ V_43 ] ) ;
V_28 -> V_38 = F_11 ( V_3 [ V_42 ] ) - 1 ;
V_28 -> V_39 = F_11 ( V_3 [ V_41 ] ) + 100 ;
F_14 ( & V_6 -> V_32 , L_3
L_2 , V_33 , V_28 -> V_34 ,
V_28 -> V_35 , V_28 -> V_36 , V_28 -> V_37 , V_28 -> V_38 , V_28 -> V_39 ,
V_28 -> V_40 ) ;
return F_17 ( V_28 ) ;
}
static int F_18 ( struct V_5 * V_6 , struct V_50 * V_51 )
{
struct V_1 * V_1 = F_13 ( V_6 ) ;
char V_3 [ 3 ] , V_52 = 0 ;
int V_30 , V_29 ;
F_14 ( & V_6 -> V_32 , L_4\
L_2 , V_33 , V_51 -> time . V_34 ,
V_51 -> time . V_35 , V_51 -> time . V_36 , V_51 -> time . V_37 ,
V_51 -> time . V_38 , V_51 -> time . V_39 , V_51 -> time . V_40 ) ;
V_30 = F_1 ( V_1 , V_23 , & V_52 , sizeof( V_52 ) ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_3 ( V_1 , V_19 , & V_52 , sizeof( V_52 ) ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_51 -> V_53 )
V_52 = V_54 ;
else
V_52 = V_55 ;
V_52 = F_15 ( V_52 ) ;
V_30 = F_1 ( V_1 , V_23 , & V_52 , sizeof( V_52 ) ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_51 -> time . V_40 != - 1 )
V_3 [ V_56 ] = F_9 ( V_51 -> time . V_40 ) | 0x80 ;
else
V_3 [ V_56 ] = 0 ;
V_3 [ V_57 ] = F_8 ( V_1 ,
V_51 -> time . V_36 ) | 0x80 ;
V_3 [ V_58 ] = F_9 ( V_51 -> time . V_35 ) | 0x80 ;
if ( V_51 -> time . V_36 >= 12 )
V_3 [ V_57 ] |= 0x40 ;
for ( V_29 = 0 ; V_29 < 3 ; ++ V_29 )
V_3 [ V_29 ] = F_15 ( V_3 [ V_29 ] ) ;
V_30 = F_1 ( V_1 , V_59 , V_3 ,
sizeof( V_3 ) ) ;
return V_30 ;
}
static int F_19 ( struct V_5 * V_6 , struct V_50 * V_51 )
{
struct V_1 * V_1 = F_13 ( V_6 ) ;
char V_3 [ 3 ] , V_52 ;
int V_29 , V_30 ;
V_30 = F_3 ( V_1 , V_23 , & V_52 , sizeof( V_52 ) ) ;
if ( V_30 < 0 )
return V_30 ;
if ( ( F_15 ( V_52 ) & V_60 ) != V_54 ) {
V_51 -> V_53 = 0 ;
return 0 ;
} else {
V_51 -> V_53 = 1 ;
}
V_30 = F_3 ( V_1 , V_59 , V_3 , sizeof( V_3 ) ) ;
if ( V_30 < 0 )
return V_30 ;
for ( V_29 = 0 ; V_29 < 3 ; ++ V_29 )
V_3 [ V_29 ] = F_15 ( V_3 [ V_29 ] ) ;
if ( V_3 [ V_56 ] & 0x80 )
V_51 -> time . V_40 =
F_11 ( V_3 [ V_56 ] & ~ 0x80 ) ;
if ( V_3 [ V_57 ] & 0x80 )
V_51 -> time . V_36 =
F_10 ( V_1 ,
V_3 [ V_57 ] & ~ 0x80 ) ;
if ( V_3 [ V_58 ] & 0x80 )
V_51 -> time . V_35 = F_11 ( V_3 [ V_58 ] & ~ 0x80 ) ;
V_51 -> time . V_34 = 0 ;
F_14 ( & V_6 -> V_32 , L_5 ,
V_33 , V_51 -> time . V_35 , V_51 -> time . V_36 ,
V_51 -> time . V_40 ) ;
return 0 ;
}
static int F_20 ( struct V_61 * V_32 , struct V_50 * V_51 )
{
return F_19 ( F_21 ( V_32 ) , V_51 ) ;
}
static int F_22 ( struct V_61 * V_32 , struct V_50 * V_51 )
{
return F_18 ( F_21 ( V_32 ) , V_51 ) ;
}
static int F_23 ( struct V_61 * V_32 , struct V_27 * V_28 )
{
return F_16 ( F_21 ( V_32 ) , V_28 ) ;
}
static int F_24 ( struct V_61 * V_32 , struct V_27 * V_28 )
{
return F_12 ( F_21 ( V_32 ) , V_28 ) ;
}
static int F_25 ( struct V_61 * V_32 , unsigned int V_62 ,
unsigned long V_63 )
{
struct V_5 * V_6 = F_21 ( V_32 ) ;
struct V_1 * V_1 = F_13 ( V_6 ) ;
char V_52 ;
int V_30 ;
switch ( V_62 ) {
case V_64 :
V_30 = F_5 ( V_1 , & V_52 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( F_26 ( ( void V_65 * ) V_63 , & V_30 , sizeof( int ) ) )
return - V_66 ;
break;
case V_67 :
V_30 = F_4 ( V_1 ) ;
if ( V_30 < 0 )
return V_30 ;
break;
default:
return - V_68 ;
}
return 0 ;
}
static int F_27 ( struct V_5 * V_6 ,
const struct V_69 * V_70 )
{
int V_30 , V_71 ;
unsigned int V_29 ;
struct V_1 * V_1 ;
struct V_27 V_28 ;
char V_3 , V_22 ;
if ( ! F_28 ( V_6 -> V_10 , V_72 ) ) {
V_30 = - V_73 ;
goto exit;
}
V_1 = F_29 ( & V_6 -> V_32 , sizeof( struct V_1 ) ,
V_74 ) ;
if ( ! V_1 ) {
V_30 = - V_75 ;
goto exit;
}
V_1 -> V_6 [ 0 ] = V_6 ;
F_30 ( V_6 , V_1 ) ;
for ( V_29 = 1 ; V_29 < 8 ; ++ V_29 ) {
V_1 -> V_6 [ V_29 ] = F_31 ( V_6 -> V_10 ,
V_6 -> V_9 + V_29 ) ;
if ( ! V_1 -> V_6 [ V_29 ] ) {
F_32 ( & V_6 -> V_32 , L_6 ,
V_6 -> V_9 + V_29 ) ;
V_30 = - V_76 ;
goto V_77;
}
}
V_71 = F_5 ( V_1 , & V_22 ) ;
if ( V_71 < 0 ) {
V_30 = V_71 ;
F_32 ( & V_6 -> V_32 , L_7 ) ;
goto V_77;
}
if ( V_22 & V_18 )
V_1 -> V_26 = 1 ;
else
V_1 -> V_26 = 0 ;
if ( V_22 & V_78 ) {
V_3 = 0 ;
V_30 = F_1 ( V_1 , V_23 , & V_3 , 1 ) ;
if ( V_30 < 0 ) {
F_32 ( & V_6 -> V_32 , L_8 ) ;
goto V_77;
}
} else {
V_30 = F_7 ( V_1 ) ;
if ( V_30 < 0 ) {
F_32 ( & V_6 -> V_32 , L_9 ) ;
goto V_77;
}
}
if ( V_71 > 0 || F_16 ( V_6 , & V_28 ) < 0 )
F_33 ( & V_6 -> V_32 , L_10 ) ;
F_34 ( & V_6 -> V_32 , 1 ) ;
V_1 -> V_79 = F_35 ( & V_6 -> V_32 ,
V_80 . V_81 . V_82 ,
& V_83 , V_84 ) ;
if ( F_36 ( V_1 -> V_79 ) ) {
V_30 = F_37 ( V_1 -> V_79 ) ;
goto V_77;
}
if ( V_22 & V_78 )
F_38 ( V_1 -> V_79 , 1 , V_85 ) ;
return 0 ;
V_77:
for ( V_29 = 1 ; V_29 < 8 ; ++ V_29 )
if ( V_1 -> V_6 [ V_29 ] )
F_39 ( V_1 -> V_6 [ V_29 ] ) ;
exit:
return V_30 ;
}
static int F_40 ( struct V_5 * V_6 )
{
unsigned int V_29 ;
struct V_1 * V_1 = F_13 ( V_6 ) ;
for ( V_29 = 1 ; V_29 < 8 ; ++ V_29 )
if ( V_1 -> V_6 [ V_29 ] )
F_39 ( V_1 -> V_6 [ V_29 ] ) ;
return 0 ;
}
