static inline int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
return F_2 ( V_4 -> V_8 ) & 0x01 ;
}
static inline int F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
return F_2 ( V_4 -> V_8 ) & 0x02 ? 1 : 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
if ( ! F_3 ( V_2 ) )
break;
F_5 ( V_11 ) ;
}
if ( V_10 == V_9 )
return 0 ;
return 1 ;
}
static int F_6 ( struct V_1 * V_2 ,
const struct V_12 * V_13 , int V_14 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
T_1 V_15 , V_16 , V_17 ;
int V_18 , V_19 ;
if ( V_14 )
F_7 ( 1 , L_1 , V_20 ,
V_13 -> V_21 , V_14 ) ;
else
F_7 ( 1 , L_2 , V_20 , V_13 -> V_21 ) ;
if ( V_13 -> V_21 == 0 ) {
F_8 ( V_4 -> V_22 , V_13 -> V_16 << 25 ) ;
F_8 ( V_4 -> V_23 , V_4 -> V_24 | ( 1 << 2 ) ) ;
if ( ! F_4 ( V_2 ) )
return - V_25 ;
if ( ! F_1 ( V_2 ) )
return - V_26 ;
F_7 ( 1 , L_3 , V_20 ) ;
return 0 ;
}
V_16 = ( V_13 -> V_16 << 25 ) | V_13 -> V_27 [ 0 ] ;
V_15 = V_13 -> V_27 [ 0 ] ;
V_17 = V_4 -> V_24 | ( 1 << 12 ) | ( 1 << 2 ) ;
if ( V_13 -> V_21 > 1 )
V_17 |= V_28 | V_29 ;
else if ( V_14 )
V_17 |= V_28 ;
F_8 ( V_4 -> V_22 , V_16 ) ;
F_8 ( V_4 -> V_30 , V_15 ) ;
F_8 ( V_4 -> V_23 , V_17 ) ;
if ( ! F_4 ( V_2 ) )
goto V_31;
if ( V_32 ) {
F_9 ( L_4 , V_13 -> V_16 << 1 , V_13 -> V_27 [ 0 ] ) ;
if ( ! ( V_17 & V_28 ) )
F_9 ( L_5 ) ;
}
for ( V_19 = 1 ; V_19 < V_13 -> V_21 ; V_19 ++ ) {
V_15 = V_13 -> V_27 [ V_19 ] ;
V_17 = V_4 -> V_24 | ( 1 << 12 ) | ( 1 << 2 ) ;
if ( V_19 < V_13 -> V_21 - 1 )
V_17 |= V_28 | V_29 ;
else if ( V_14 )
V_17 |= V_28 ;
F_8 ( V_4 -> V_22 , V_16 ) ;
F_8 ( V_4 -> V_30 , V_15 ) ;
F_8 ( V_4 -> V_23 , V_17 ) ;
if ( ! F_4 ( V_2 ) )
goto V_31;
if ( V_32 ) {
F_7 ( 1 , L_6 , V_13 -> V_27 [ V_19 ] ) ;
if ( ! ( V_17 & V_28 ) )
F_7 ( 1 , L_5 ) ;
}
}
return V_13 -> V_21 ;
V_31:
V_18 = - V_25 ;
if ( V_32 )
F_9 ( V_33 L_7 , V_18 ) ;
return V_18 ;
}
static int F_10 ( struct V_1 * V_2 ,
const struct V_12 * V_13 , int V_34 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
T_1 V_17 , V_19 ;
int V_18 ;
if ( V_32 && ! V_34 )
F_7 ( 1 , L_2 , V_20 , V_13 -> V_21 ) ;
if ( V_13 -> V_21 == 0 ) {
F_8 ( V_4 -> V_22 , V_13 -> V_16 << 25 ) ;
F_8 ( V_4 -> V_23 , V_4 -> V_24 | ( 1 << 2 ) | 1 ) ;
if ( ! F_4 ( V_2 ) )
return - V_25 ;
if ( ! F_1 ( V_2 ) )
return - V_26 ;
F_7 ( 1 , L_3 , V_20 ) ;
return 0 ;
}
if ( V_32 ) {
if ( V_34 )
F_7 ( 1 , L_8 ) ;
else
F_7 ( 1 , L_9 , ( V_13 -> V_16 << 1 ) + 1 ) ;
}
for ( V_19 = 0 ; V_19 < V_13 -> V_21 ; V_19 ++ ) {
V_17 = V_4 -> V_24 | ( 1 << 12 ) | ( 1 << 2 ) | 1 ;
if ( V_19 < V_13 -> V_21 - 1 )
V_17 |= V_28 | V_29 ;
F_8 ( V_4 -> V_22 , V_13 -> V_16 << 25 ) ;
F_8 ( V_4 -> V_23 , V_17 ) ;
if ( ! F_4 ( V_2 ) )
goto V_31;
V_13 -> V_27 [ V_19 ] = F_2 ( V_4 -> V_35 ) & 0xff ;
if ( V_32 ) {
F_7 ( 1 , L_6 , V_13 -> V_27 [ V_19 ] ) ;
if ( ! ( V_17 & V_28 ) )
F_7 ( 1 , L_5 ) ;
}
}
return V_13 -> V_21 ;
V_31:
V_18 = - V_25 ;
if ( V_32 )
F_9 ( V_33 L_7 , V_18 ) ;
return V_18 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_12 * V_36 , int V_37 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_38 , V_18 = 0 ;
F_7 ( 1 , L_10 , V_20 , V_37 ) ;
for ( V_38 = 0 ; V_38 < V_37 ; V_38 ++ ) {
F_7 ( 1 , L_11 ,
V_20 , V_37 , V_36 [ V_38 ] . V_16 , V_36 [ V_38 ] . V_21 ) ;
if ( V_36 [ V_38 ] . V_39 & V_40 ) {
V_18 = F_10 ( V_2 , & V_36 [ V_38 ] , 0 ) ;
} else if ( V_38 + 1 < V_37 && ( V_36 [ V_38 + 1 ] . V_39 & V_40 ) &&
V_36 [ V_38 ] . V_16 == V_36 [ V_38 + 1 ] . V_16 ) {
V_18 = F_6 ( V_2 , & V_36 [ V_38 ] ,
V_36 [ V_38 + 1 ] . V_21 ) ;
if ( V_18 < 0 )
goto V_41;
V_38 ++ ;
V_18 = F_10 ( V_2 , & V_36 [ V_38 ] , 1 ) ;
} else {
V_18 = F_6 ( V_2 , & V_36 [ V_38 ] , 0 ) ;
}
if ( V_18 < 0 )
goto V_41;
}
return V_37 ;
V_41:
return V_18 ;
}
static T_1 F_12 ( struct V_1 * V_42 )
{
return V_43 | V_44 ;
}
static void F_13 ( char * V_45 , struct V_46 * V_47 )
{
unsigned char V_27 ;
int V_38 , V_48 ;
for ( V_38 = 0 ; V_38 < 128 ; V_38 ++ ) {
V_47 -> V_16 = V_38 ;
V_48 = F_14 ( V_47 , & V_27 , 0 ) ;
if ( V_48 < 0 )
continue;
F_9 ( V_49 L_12 ,
V_45 , V_38 << 1 , V_50 [ V_38 ] ? V_50 [ V_38 ] : L_13 ) ;
}
}
int F_15 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_7 ;
F_7 ( 1 , L_14 , V_20 , V_4 -> V_51 ) ;
memcpy ( & V_4 -> V_2 , & V_52 ,
sizeof( V_4 -> V_2 ) ) ;
memcpy ( & V_4 -> V_53 , & V_54 ,
sizeof( V_4 -> V_53 ) ) ;
memcpy ( & V_4 -> V_46 , & V_55 ,
sizeof( V_4 -> V_46 ) ) ;
V_4 -> V_2 . V_7 . V_56 = & V_7 -> V_57 -> V_7 ;
F_16 ( V_4 -> V_2 . V_45 , V_4 -> V_7 -> V_45 ,
sizeof( V_4 -> V_2 . V_45 ) ) ;
V_4 -> V_53 . V_58 = V_4 ;
V_4 -> V_2 . V_5 = V_4 ;
F_17 ( & V_4 -> V_2 , & V_7 -> V_59 ) ;
F_18 ( & V_4 -> V_2 ) ;
V_4 -> V_46 . V_60 = & V_4 -> V_2 ;
if ( 0 == V_4 -> V_61 ) {
F_7 ( 1 , L_15 , V_7 -> V_45 , V_4 -> V_51 ) ;
if ( V_62 ) {
F_9 ( V_49 L_16 ,
V_7 -> V_45 , V_4 -> V_51 ) ;
F_13 ( V_7 -> V_45 , & V_4 -> V_46 ) ;
}
} else
F_9 ( V_63 L_17 ,
V_7 -> V_45 , V_4 -> V_51 ) ;
if ( 0 == V_4 -> V_61 ) {
struct V_64 V_65 ;
const unsigned short V_66 [] = {
0x6b , V_67
} ;
memset ( & V_65 , 0 , sizeof( struct V_64 ) ) ;
F_16 ( V_65 . type , L_18 , V_68 ) ;
F_19 ( & V_4 -> V_2 , & V_65 , V_66 ,
V_69 ) ;
}
return V_4 -> V_61 ;
}
int F_20 ( struct V_3 * V_4 )
{
F_21 ( & V_4 -> V_2 ) ;
return 0 ;
}
void F_22 ( struct V_6 * V_7 , int V_70 )
{
char V_71 [ 3 ] ;
struct V_12 V_13 ;
F_7 ( 1 , L_19 , V_20 , V_70 ) ;
V_71 [ 0 ] = 0x01 ;
V_71 [ 1 ] = 0x44 ;
if ( V_70 == 1 )
V_71 [ 2 ] = 0x05 ;
else
V_71 [ 2 ] = 0x00 ;
V_13 . V_16 = 0x44 ;
V_13 . V_39 = V_72 ;
V_13 . V_21 = 3 ;
V_13 . V_27 = V_71 ;
F_11 ( & V_7 -> V_73 [ 2 ] . V_2 , & V_13 , 1 ) ;
}
