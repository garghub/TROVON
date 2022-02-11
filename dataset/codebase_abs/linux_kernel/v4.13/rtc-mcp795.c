static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 ;
T_1 V_9 [ 2 ] ;
V_9 [ 0 ] = V_10 ;
V_9 [ 1 ] = V_3 ;
V_8 = F_3 ( V_7 , V_9 , sizeof( V_9 ) , V_4 , V_5 ) ;
if ( V_8 )
F_4 ( V_2 , L_1 ,
V_5 , V_3 ) ;
return V_8 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_11 , T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 ;
T_1 V_9 [ 2 + V_5 ] ;
V_9 [ 0 ] = V_12 ;
V_9 [ 1 ] = V_3 ;
memcpy ( & V_9 [ 2 ] , V_11 , V_5 ) ;
V_8 = F_6 ( V_7 , V_9 , 2 + V_5 ) ;
if ( V_8 )
F_4 ( V_2 , L_2 ,
V_5 , V_3 ) ;
return V_8 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_13 , T_1 V_14 )
{
int V_8 ;
T_1 V_15 ;
V_8 = F_1 ( V_2 , V_3 , & V_15 , 1 ) ;
if ( V_8 )
return V_8 ;
if ( ( V_15 & V_13 ) != V_14 ) {
V_15 = ( V_15 & ~ V_13 ) | V_14 ;
V_8 = F_5 ( V_2 , V_3 , & V_15 , 1 ) ;
}
return V_8 ;
}
static int F_8 ( struct V_1 * V_2 , bool * V_16 )
{
int V_17 = 5 ;
int V_8 ;
T_1 V_11 ;
V_8 = F_7 ( V_2 , V_18 , V_19 , 0 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_1 ( V_2 , V_20 , & V_11 , 1 ) ;
if ( V_8 )
return V_8 ;
* V_16 = ! ! ( V_11 & V_21 ) ;
V_8 = F_7 (
V_2 , V_20 , V_21 , 0 ) ;
if ( V_8 )
return V_8 ;
do {
F_9 ( 700 , 800 ) ;
V_8 = F_1 ( V_2 , V_22 , & V_11 , 1 ) ;
if ( V_8 )
break;
if ( ! ( V_11 & V_23 ) )
break;
} while ( -- V_17 );
return ! V_17 ? - V_24 : V_8 ;
}
static int F_10 ( struct V_1 * V_2 , bool * V_16 )
{
if ( V_16 ) {
T_1 V_11 = * V_16 ? V_21 : 0 ;
int V_8 ;
V_8 = F_7 (
V_2 , V_20 , V_21 , V_11 ) ;
if ( V_8 )
return V_8 ;
}
return F_7 (
V_2 , V_18 , V_19 , V_19 ) ;
}
static int F_11 ( struct V_1 * V_2 , bool V_25 )
{
int V_8 ;
F_12 ( V_2 , L_3 , V_25 ? L_4 : L_5 ) ;
if ( V_25 ) {
V_8 = F_7 ( V_2 , V_26 ,
V_27 , 0 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_7 ( V_2 , V_20 ,
V_28 , V_28 ) ;
} else {
V_8 = F_7 ( V_2 , V_20 ,
V_28 | V_29 , 0 ) ;
}
return V_8 ;
}
static int F_13 ( struct V_1 * V_2 , struct V_30 * V_31 )
{
int V_8 ;
T_1 V_11 [ 7 ] ;
bool V_16 ;
V_8 = F_8 ( V_2 , & V_16 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_1 ( V_2 , V_18 , V_11 , sizeof( V_11 ) ) ;
if ( V_8 )
return V_8 ;
V_11 [ 0 ] = ( V_11 [ 0 ] & 0x80 ) | F_14 ( V_31 -> V_32 ) ;
V_11 [ 1 ] = ( V_11 [ 1 ] & 0x80 ) | F_14 ( V_31 -> V_33 ) ;
V_11 [ 2 ] = F_14 ( V_31 -> V_34 ) ;
V_11 [ 3 ] = ( V_11 [ 3 ] & 0xF8 ) | F_14 ( V_31 -> V_35 + 1 ) ;
V_11 [ 4 ] = F_14 ( V_31 -> V_36 ) ;
V_11 [ 5 ] = ( V_11 [ 5 ] & V_37 ) | F_14 ( V_31 -> V_38 + 1 ) ;
if ( V_31 -> V_39 > 100 )
V_31 -> V_39 -= 100 ;
V_11 [ 6 ] = F_14 ( V_31 -> V_39 ) ;
V_8 = F_5 ( V_2 , V_18 , V_11 , 5 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_5 ( V_2 , V_40 , & V_11 [ 5 ] , 2 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_10 ( V_2 , V_16 ? & V_16 : NULL ) ;
if ( V_8 )
return V_8 ;
F_12 ( V_2 , L_6 ,
V_31 -> V_39 + 1900 , V_31 -> V_38 , V_31 -> V_36 ,
V_31 -> V_35 , V_31 -> V_34 , V_31 -> V_33 , V_31 -> V_32 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , struct V_30 * V_31 )
{
int V_8 ;
T_1 V_11 [ 7 ] ;
V_8 = F_1 ( V_2 , V_18 , V_11 , sizeof( V_11 ) ) ;
if ( V_8 )
return V_8 ;
V_31 -> V_32 = F_16 ( V_11 [ 0 ] & 0x7F ) ;
V_31 -> V_33 = F_16 ( V_11 [ 1 ] & 0x7F ) ;
V_31 -> V_34 = F_16 ( V_11 [ 2 ] & 0x3F ) ;
V_31 -> V_35 = F_16 ( V_11 [ 3 ] & 0x07 ) - 1 ;
V_31 -> V_36 = F_16 ( V_11 [ 4 ] & 0x3F ) ;
V_31 -> V_38 = F_16 ( V_11 [ 5 ] & 0x1F ) - 1 ;
V_31 -> V_39 = F_16 ( V_11 [ 6 ] ) + 100 ;
F_12 ( V_2 , L_7 ,
V_31 -> V_39 + 1900 , V_31 -> V_38 , V_31 -> V_36 ,
V_31 -> V_35 , V_31 -> V_34 , V_31 -> V_33 , V_31 -> V_32 ) ;
return F_17 ( V_31 ) ;
}
static int F_18 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
struct V_30 V_43 ;
T_2 V_44 ;
T_2 V_45 ;
T_1 V_15 [ 6 ] ;
int V_8 ;
V_8 = F_15 ( V_2 , & V_43 ) ;
if ( V_8 )
return V_8 ;
V_44 = F_19 ( & V_43 ) ;
V_45 = F_19 ( & V_42 -> time ) ;
if ( V_45 <= V_44 )
return - V_46 ;
if ( ( V_45 - V_44 ) >=
( V_47 * ( 365 + F_20 ( V_42 -> time . V_39 ) ) ) )
return - V_48 ;
V_8 = F_11 ( V_2 , false ) ;
if ( V_8 )
return V_8 ;
V_8 = F_1 ( V_2 , V_49 , V_15 , sizeof( V_15 ) ) ;
if ( V_8 )
return V_8 ;
V_42 -> time . V_39 = - 1 ;
V_42 -> time . V_50 = - 1 ;
V_42 -> time . V_51 = - 1 ;
V_15 [ 0 ] = ( V_15 [ 0 ] & 0x80 ) | F_14 ( V_42 -> time . V_32 ) ;
V_15 [ 1 ] = ( V_15 [ 1 ] & 0x80 ) | F_14 ( V_42 -> time . V_33 ) ;
V_15 [ 2 ] = ( V_15 [ 2 ] & 0xE0 ) | F_14 ( V_42 -> time . V_34 ) ;
V_15 [ 3 ] = ( V_15 [ 3 ] & 0x80 ) | F_14 ( V_42 -> time . V_35 + 1 ) ;
V_15 [ 3 ] |= ( V_52 | V_53 | V_54 ) ;
V_15 [ 4 ] = ( V_15 [ 4 ] & 0xC0 ) | F_14 ( V_42 -> time . V_36 ) ;
V_15 [ 5 ] = ( V_15 [ 5 ] & 0xE0 ) | F_14 ( V_42 -> time . V_38 + 1 ) ;
V_8 = F_5 ( V_2 , V_49 , V_15 , sizeof( V_15 ) ) ;
if ( V_8 )
return V_8 ;
if ( V_42 -> V_55 ) {
V_8 = F_11 ( V_2 , true ) ;
if ( V_8 )
return V_8 ;
F_12 ( V_2 , L_8 ) ;
}
F_12 ( V_2 , L_9 ,
V_42 -> time . V_38 , V_42 -> time . V_36 , V_42 -> time . V_35 ,
V_42 -> time . V_34 , V_42 -> time . V_33 , V_42 -> time . V_32 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
T_1 V_11 [ 6 ] ;
int V_8 ;
V_8 = F_1 (
V_2 , V_49 , V_11 , sizeof( V_11 ) ) ;
if ( V_8 )
return V_8 ;
V_42 -> time . V_32 = F_16 ( V_11 [ 0 ] & 0x7F ) ;
V_42 -> time . V_33 = F_16 ( V_11 [ 1 ] & 0x7F ) ;
V_42 -> time . V_34 = F_16 ( V_11 [ 2 ] & 0x1F ) ;
V_42 -> time . V_35 = F_16 ( V_11 [ 3 ] & 0x07 ) - 1 ;
V_42 -> time . V_36 = F_16 ( V_11 [ 4 ] & 0x3F ) ;
V_42 -> time . V_38 = F_16 ( V_11 [ 5 ] & 0x1F ) - 1 ;
V_42 -> time . V_39 = - 1 ;
V_42 -> time . V_50 = - 1 ;
V_42 -> time . V_51 = - 1 ;
F_12 ( V_2 , L_10 ,
V_42 -> time . V_38 , V_42 -> time . V_36 , V_42 -> time . V_35 ,
V_42 -> time . V_34 , V_42 -> time . V_33 , V_42 -> time . V_32 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , unsigned int V_55 )
{
return F_11 ( V_2 , ! ! V_55 ) ;
}
static T_3 F_23 ( int V_56 , void * V_11 )
{
struct V_6 * V_7 = V_11 ;
struct V_57 * V_58 = F_24 ( V_7 ) ;
struct V_59 * V_60 = & V_58 -> V_61 ;
int V_8 ;
F_25 ( V_60 ) ;
V_8 = F_11 ( & V_7 -> V_2 , false ) ;
if ( V_8 )
F_4 ( & V_7 -> V_2 ,
L_11 , V_8 ) ;
F_26 ( V_58 , 1 , V_62 | V_63 ) ;
F_27 ( V_60 ) ;
return V_64 ;
}
static int F_28 ( struct V_6 * V_7 )
{
struct V_57 * V_58 ;
int V_8 ;
V_7 -> V_65 = V_66 ;
V_7 -> V_67 = 8 ;
V_8 = F_29 ( V_7 ) ;
if ( V_8 ) {
F_4 ( & V_7 -> V_2 , L_12 ) ;
return V_8 ;
}
F_10 ( & V_7 -> V_2 , NULL ) ;
F_7 ( & V_7 -> V_2 , 0x03 , V_68 , 0 ) ;
V_58 = F_30 ( & V_7 -> V_2 , L_13 ,
& V_69 , V_70 ) ;
if ( F_31 ( V_58 ) )
return F_32 ( V_58 ) ;
F_33 ( V_7 , V_58 ) ;
if ( V_7 -> V_56 > 0 ) {
F_12 ( & V_7 -> V_2 , L_14 ) ;
F_7 ( & V_7 -> V_2 , V_26 ,
V_27 , 0 ) ;
V_8 = F_34 ( & V_7 -> V_2 , V_7 -> V_56 , NULL ,
F_23 , V_71 | V_72 ,
F_35 ( & V_58 -> V_2 ) , V_7 ) ;
if ( V_8 )
F_4 ( & V_7 -> V_2 , L_15 ,
V_7 -> V_56 , V_8 ) ;
else
F_36 ( & V_7 -> V_2 , true ) ;
}
return 0 ;
}
