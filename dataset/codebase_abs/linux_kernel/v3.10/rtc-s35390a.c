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
char V_3 [ 1 ] ;
if ( F_3 ( V_1 , V_14 , V_3 , sizeof( V_3 ) ) < 0 )
return - V_11 ;
if ( ! ( V_3 [ 0 ] & ( V_15 | V_16 ) ) )
return 0 ;
V_3 [ 0 ] |= ( V_17 | V_18 ) ;
V_3 [ 0 ] &= 0xf0 ;
return F_1 ( V_1 , V_14 , V_3 , sizeof( V_3 ) ) ;
}
static int F_5 ( struct V_1 * V_1 )
{
char V_3 [ 1 ] ;
if ( F_3 ( V_1 , V_19 , V_3 , sizeof( V_3 ) ) < 0 )
return - V_11 ;
if ( ! ( V_3 [ 0 ] & V_20 ) )
return 0 ;
V_3 [ 0 ] &= ~ V_20 ;
return F_1 ( V_1 , V_19 , V_3 , sizeof( V_3 ) ) ;
}
static char F_6 ( struct V_1 * V_1 , int V_21 )
{
if ( V_1 -> V_22 )
return F_7 ( V_21 ) ;
if ( V_21 < 12 )
return F_7 ( V_21 ) ;
return 0x40 | F_7 ( V_21 - 12 ) ;
}
static int F_8 ( struct V_1 * V_1 , char V_2 )
{
unsigned V_21 ;
if ( V_1 -> V_22 )
return F_9 ( V_2 & 0x3f ) ;
V_21 = F_9 ( V_2 & 0x3f ) ;
if ( V_2 & 0x40 )
V_21 += 12 ;
return V_21 ;
}
static int F_10 ( struct V_5 * V_6 , struct V_23 * V_24 )
{
struct V_1 * V_1 = F_11 ( V_6 ) ;
int V_25 , V_26 ;
char V_3 [ 7 ] ;
F_12 ( & V_6 -> V_27 , L_1
L_2 , V_28 , V_24 -> V_29 ,
V_24 -> V_30 , V_24 -> V_31 , V_24 -> V_32 , V_24 -> V_33 , V_24 -> V_34 ,
V_24 -> V_35 ) ;
V_3 [ V_36 ] = F_7 ( V_24 -> V_34 - 100 ) ;
V_3 [ V_37 ] = F_7 ( V_24 -> V_33 + 1 ) ;
V_3 [ V_38 ] = F_7 ( V_24 -> V_32 ) ;
V_3 [ V_39 ] = F_7 ( V_24 -> V_35 ) ;
V_3 [ V_40 ] = F_6 ( V_1 , V_24 -> V_31 ) ;
V_3 [ V_41 ] = F_7 ( V_24 -> V_30 ) ;
V_3 [ V_42 ] = F_7 ( V_24 -> V_29 ) ;
for ( V_25 = 0 ; V_25 < 7 ; ++ V_25 )
V_3 [ V_25 ] = F_13 ( V_3 [ V_25 ] ) ;
V_26 = F_1 ( V_1 , V_43 , V_3 , sizeof( V_3 ) ) ;
return V_26 ;
}
static int F_14 ( struct V_5 * V_6 , struct V_23 * V_24 )
{
struct V_1 * V_1 = F_11 ( V_6 ) ;
char V_3 [ 7 ] ;
int V_25 , V_26 ;
V_26 = F_3 ( V_1 , V_43 , V_3 , sizeof( V_3 ) ) ;
if ( V_26 < 0 )
return V_26 ;
for ( V_25 = 0 ; V_25 < 7 ; ++ V_25 )
V_3 [ V_25 ] = F_13 ( V_3 [ V_25 ] ) ;
V_24 -> V_29 = F_9 ( V_3 [ V_42 ] ) ;
V_24 -> V_30 = F_9 ( V_3 [ V_41 ] ) ;
V_24 -> V_31 = F_8 ( V_1 , V_3 [ V_40 ] ) ;
V_24 -> V_35 = F_9 ( V_3 [ V_39 ] ) ;
V_24 -> V_32 = F_9 ( V_3 [ V_38 ] ) ;
V_24 -> V_33 = F_9 ( V_3 [ V_37 ] ) - 1 ;
V_24 -> V_34 = F_9 ( V_3 [ V_36 ] ) + 100 ;
F_12 ( & V_6 -> V_27 , L_3
L_2 , V_28 , V_24 -> V_29 ,
V_24 -> V_30 , V_24 -> V_31 , V_24 -> V_32 , V_24 -> V_33 , V_24 -> V_34 ,
V_24 -> V_35 ) ;
return F_15 ( V_24 ) ;
}
static int F_16 ( struct V_5 * V_6 , struct V_44 * V_45 )
{
struct V_1 * V_1 = F_11 ( V_6 ) ;
char V_3 [ 3 ] , V_46 = 0 ;
int V_26 , V_25 ;
F_12 ( & V_6 -> V_27 , L_4\
L_2 , V_28 , V_45 -> time . V_29 ,
V_45 -> time . V_30 , V_45 -> time . V_31 , V_45 -> time . V_32 ,
V_45 -> time . V_33 , V_45 -> time . V_34 , V_45 -> time . V_35 ) ;
V_26 = F_1 ( V_1 , V_19 , & V_46 , sizeof( V_46 ) ) ;
if ( V_26 < 0 )
return V_26 ;
V_26 = F_3 ( V_1 , V_14 , & V_46 , sizeof( V_46 ) ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_45 -> V_47 )
V_46 = V_48 ;
else
V_46 = V_49 ;
V_46 = F_13 ( V_46 ) ;
V_26 = F_1 ( V_1 , V_19 , & V_46 , sizeof( V_46 ) ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_45 -> time . V_35 != - 1 )
V_3 [ V_50 ] = F_7 ( V_45 -> time . V_35 ) | 0x80 ;
V_3 [ V_51 ] = F_6 ( V_1 ,
V_45 -> time . V_31 ) | 0x80 ;
V_3 [ V_52 ] = F_7 ( V_45 -> time . V_30 ) | 0x80 ;
if ( V_45 -> time . V_31 >= 12 )
V_3 [ V_51 ] |= 0x40 ;
for ( V_25 = 0 ; V_25 < 3 ; ++ V_25 )
V_3 [ V_25 ] = F_13 ( V_3 [ V_25 ] ) ;
V_26 = F_1 ( V_1 , V_53 , V_3 ,
sizeof( V_3 ) ) ;
return V_26 ;
}
static int F_17 ( struct V_5 * V_6 , struct V_44 * V_45 )
{
struct V_1 * V_1 = F_11 ( V_6 ) ;
char V_3 [ 3 ] , V_46 ;
int V_25 , V_26 ;
V_26 = F_3 ( V_1 , V_19 , & V_46 , sizeof( V_46 ) ) ;
if ( V_26 < 0 )
return V_26 ;
if ( F_13 ( V_46 ) != V_48 )
return - V_54 ;
V_26 = F_3 ( V_1 , V_53 , V_3 , sizeof( V_3 ) ) ;
if ( V_26 < 0 )
return V_26 ;
for ( V_25 = 0 ; V_25 < 3 ; ++ V_25 ) {
V_3 [ V_25 ] = F_13 ( V_3 [ V_25 ] ) ;
V_3 [ V_25 ] &= ~ 0x80 ;
}
V_45 -> time . V_35 = F_9 ( V_3 [ V_50 ] ) ;
V_45 -> time . V_31 = F_8 ( V_1 ,
V_3 [ V_51 ] ) ;
V_45 -> time . V_30 = F_9 ( V_3 [ V_52 ] ) ;
F_12 ( & V_6 -> V_27 , L_5 ,
V_28 , V_45 -> time . V_30 , V_45 -> time . V_31 ,
V_45 -> time . V_35 ) ;
return 0 ;
}
static int F_18 ( struct V_55 * V_27 , struct V_44 * V_45 )
{
return F_17 ( F_19 ( V_27 ) , V_45 ) ;
}
static int F_20 ( struct V_55 * V_27 , struct V_44 * V_45 )
{
return F_16 ( F_19 ( V_27 ) , V_45 ) ;
}
static int F_21 ( struct V_55 * V_27 , struct V_23 * V_24 )
{
return F_14 ( F_19 ( V_27 ) , V_24 ) ;
}
static int F_22 ( struct V_55 * V_27 , struct V_23 * V_24 )
{
return F_10 ( F_19 ( V_27 ) , V_24 ) ;
}
static int F_23 ( struct V_5 * V_6 ,
const struct V_56 * V_57 )
{
int V_26 ;
unsigned int V_25 ;
struct V_1 * V_1 ;
struct V_23 V_24 ;
char V_3 [ 1 ] ;
if ( ! F_24 ( V_6 -> V_10 , V_58 ) ) {
V_26 = - V_59 ;
goto exit;
}
V_1 = F_25 ( & V_6 -> V_27 , sizeof( struct V_1 ) ,
V_60 ) ;
if ( ! V_1 ) {
V_26 = - V_61 ;
goto exit;
}
V_1 -> V_6 [ 0 ] = V_6 ;
F_26 ( V_6 , V_1 ) ;
for ( V_25 = 1 ; V_25 < 8 ; ++ V_25 ) {
V_1 -> V_6 [ V_25 ] = F_27 ( V_6 -> V_10 ,
V_6 -> V_9 + V_25 ) ;
if ( ! V_1 -> V_6 [ V_25 ] ) {
F_28 ( & V_6 -> V_27 , L_6 ,
V_6 -> V_9 + V_25 ) ;
V_26 = - V_62 ;
goto V_63;
}
}
V_26 = F_4 ( V_1 ) ;
if ( V_26 < 0 ) {
F_28 ( & V_6 -> V_27 , L_7 ) ;
goto V_63;
}
V_26 = F_5 ( V_1 ) ;
if ( V_26 < 0 ) {
F_28 ( & V_6 -> V_27 , L_8 ) ;
goto V_63;
}
V_26 = F_3 ( V_1 , V_14 , V_3 , sizeof( V_3 ) ) ;
if ( V_26 < 0 ) {
F_28 ( & V_6 -> V_27 , L_9 ) ;
goto V_63;
}
if ( V_3 [ 0 ] & V_18 )
V_1 -> V_22 = 1 ;
else
V_1 -> V_22 = 0 ;
if ( F_14 ( V_6 , & V_24 ) < 0 )
F_29 ( & V_6 -> V_27 , L_10 ) ;
F_30 ( & V_6 -> V_27 , 1 ) ;
V_1 -> V_64 = F_31 ( & V_6 -> V_27 ,
V_65 . V_66 . V_67 ,
& V_68 , V_69 ) ;
if ( F_32 ( V_1 -> V_64 ) ) {
V_26 = F_33 ( V_1 -> V_64 ) ;
goto V_63;
}
return 0 ;
V_63:
for ( V_25 = 1 ; V_25 < 8 ; ++ V_25 )
if ( V_1 -> V_6 [ V_25 ] )
F_34 ( V_1 -> V_6 [ V_25 ] ) ;
exit:
return V_26 ;
}
static int F_35 ( struct V_5 * V_6 )
{
unsigned int V_25 ;
struct V_1 * V_1 = F_11 ( V_6 ) ;
for ( V_25 = 1 ; V_25 < 8 ; ++ V_25 )
if ( V_1 -> V_6 [ V_25 ] )
F_34 ( V_1 -> V_6 [ V_25 ] ) ;
return 0 ;
}
