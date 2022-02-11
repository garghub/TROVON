static inline int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_2 ( V_4 , V_6 ) &
V_7 ? 0 : 1 ;
}
static inline int F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_2 ( V_4 , V_6 ) &
V_8 ? 0 : 1 ;
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
static inline int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_2 ( V_4 , V_6 ) &
V_12 ? 0 : 1 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
if ( ! F_6 ( V_2 ) )
break;
F_5 ( V_11 ) ;
}
if ( V_10 == V_9 )
return 0 ;
return 1 ;
}
static inline int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_2 ( V_4 , V_6 ) &
V_13 ? 1 : 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
if ( F_8 ( V_2 ) )
break;
F_5 ( V_11 ) ;
}
if ( V_10 == V_9 )
return 0 ;
return 1 ;
}
static inline int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_2 ( V_4 , V_6 ) &
V_14 ? 1 : 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
if ( ! F_10 ( V_2 ) )
break;
F_5 ( V_11 ) ;
}
if ( V_10 == V_9 )
return 0 ;
return 1 ;
}
static int F_12 ( struct V_1 * V_2 ,
const struct V_15 * V_16 , int V_17 )
{
int V_18 , V_19 = 0 ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_13 ( 4 , L_1 , V_20 ) ;
F_14 ( V_4 , V_21 , 0x01 ) ;
if ( ( ( V_4 -> V_22 . V_23 == V_24 ) ||
( V_4 -> V_22 . V_23 == V_25 ) ) &&
( V_4 -> V_22 . V_26 == V_16 -> V_27 ) &&
( V_16 -> V_28 == 64 ) ) {
F_14 ( V_4 , V_29 ,
V_30 ) ;
} else {
F_14 ( V_4 , V_29 ,
V_4 -> V_22 . V_31 ) ;
}
F_14 ( V_4 , V_32 , V_16 -> V_27 << 1 ) ;
F_13 ( 4 , L_2 , V_16 -> V_27 ) ;
if ( V_16 -> V_28 == 0 ) {
F_14 ( V_4 , V_33 ,
V_34 ) ;
if ( ! F_11 ( V_2 ) )
return - V_35 ;
if ( F_4 ( V_2 ) )
return - V_35 ;
return 0 ;
}
for ( V_18 = 0 ; V_18 < V_16 -> V_28 ; ) {
F_13 ( 4 , L_3 , V_16 -> V_36 [ V_18 ] ) ;
F_14 ( V_4 , V_37 , V_16 -> V_36 [ V_18 ] ) ;
V_19 ++ ;
V_18 ++ ;
if ( ( V_19 >= 4 ) || ( V_18 >= V_16 -> V_28 ) ) {
if ( V_18 < V_16 -> V_28 )
F_14 ( V_4 , V_33 ,
V_38 |
V_39 ) ;
else
F_14 ( V_4 , V_33 ,
V_38 ) ;
V_19 = 0 ;
if ( ! F_9 ( V_2 ) )
return - V_35 ;
}
}
if ( ! F_11 ( V_2 ) )
return - V_35 ;
F_13 ( 4 , L_4 ) ;
return V_16 -> V_28 ;
}
static int F_15 ( struct V_1 * V_2 ,
const struct V_15 * V_16 , int V_40 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_18 ;
F_13 ( 4 , L_1 , V_20 ) ;
F_14 ( V_4 , V_21 , 0x01 ) ;
F_14 ( V_4 , V_29 ,
V_4 -> V_22 . V_31 ) ;
F_14 ( V_4 , V_32 , V_16 -> V_27 << 1 ) ;
F_13 ( 4 , L_5 ) ;
if ( V_16 -> V_28 == 0 ) {
F_14 ( V_4 , V_33 ,
V_34 ) ;
if ( F_4 ( V_2 ) )
return - V_35 ;
return 0 ;
}
for ( V_18 = 0 ; V_18 < V_16 -> V_28 ; ) {
V_18 ++ ;
if ( V_18 < V_16 -> V_28 )
F_14 ( V_4 , V_33 ,
V_34 |
V_39 ) ;
else
F_14 ( V_4 , V_33 ,
V_34 ) ;
if ( ! F_7 ( V_2 ) )
return - V_35 ;
V_16 -> V_36 [ V_18 - 1 ] = F_2 ( V_4 , V_41 ) &
0xff ;
F_13 ( 4 , L_3 , V_16 -> V_36 [ V_18 - 1 ] ) ;
}
if ( ! F_11 ( V_2 ) )
return - V_35 ;
F_13 ( 4 , L_4 ) ;
return V_16 -> V_28 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_15 * V_42 , int V_43 )
{
int V_18 , V_44 = 0 ;
F_13 ( 4 , L_6 , V_20 , V_43 ) ;
for ( V_18 = 0 ; V_18 < V_43 ; V_18 ++ ) {
F_13 ( 4 , L_7 ,
V_20 , V_43 , V_42 [ V_18 ] . V_27 , V_42 [ V_18 ] . V_28 ) ;
if ( V_42 [ V_18 ] . V_45 & V_46 ) {
V_44 = F_15 ( V_2 , & V_42 [ V_18 ] , 0 ) ;
} else if ( V_18 + 1 < V_43 && ( V_42 [ V_18 + 1 ] . V_45 & V_46 ) &&
V_42 [ V_18 ] . V_27 == V_42 [ V_18 + 1 ] . V_27 ) {
V_44 = F_12 ( V_2 , & V_42 [ V_18 ] ,
V_42 [ V_18 + 1 ] . V_28 ) ;
if ( V_44 < 0 )
goto V_47;
V_18 ++ ;
V_44 = F_15 ( V_2 , & V_42 [ V_18 ] , 1 ) ;
} else {
V_44 = F_12 ( V_2 , & V_42 [ V_18 ] , 0 ) ;
}
if ( V_44 < 0 )
goto V_47;
}
return V_43 ;
V_47:
return V_44 ;
}
static T_1 F_17 ( struct V_1 * V_48 )
{
return V_49 | V_50 ;
}
static void F_18 ( char * V_51 , struct V_52 * V_53 )
{
unsigned char V_36 ;
int V_18 , V_54 ;
for ( V_18 = 0 ; V_18 < 128 ; V_18 ++ ) {
V_53 -> V_27 = V_18 ;
V_54 = F_19 ( V_53 , & V_36 , 0 ) ;
if ( V_54 < 0 )
continue;
F_20 ( V_55 L_8 ,
V_51 , V_18 << 1 , V_56 [ V_18 ] ? V_56 [ V_18 ] : L_9 ) ;
}
}
int F_21 ( struct V_3 * V_4 )
{
F_13 ( 1 , L_1 , V_20 ) ;
memcpy ( & V_4 -> V_2 , & V_57 ,
sizeof( V_4 -> V_2 ) ) ;
memcpy ( & V_4 -> V_58 , & V_59 ,
sizeof( V_4 -> V_58 ) ) ;
memcpy ( & V_4 -> V_52 , & V_60 ,
sizeof( V_4 -> V_52 ) ) ;
V_4 -> V_2 . V_4 . V_61 = & V_4 -> V_62 -> V_4 ;
F_22 ( V_4 -> V_2 . V_51 , V_63 ,
sizeof( V_4 -> V_2 . V_51 ) ) ;
V_4 -> V_2 . V_64 = & V_4 -> V_58 ;
V_4 -> V_2 . V_5 = V_4 ;
F_23 ( & V_4 -> V_2 , & V_4 -> V_65 ) ;
F_24 ( & V_4 -> V_2 ) ;
V_4 -> V_52 . V_66 = & V_4 -> V_2 ;
if ( 0 == V_4 -> V_67 ) {
F_20 ( V_55 L_10 , V_63 ) ;
if ( V_68 )
F_18 ( V_63 , & V_4 -> V_52 ) ;
} else
F_20 ( V_55 L_11 , V_63 ) ;
return V_4 -> V_67 ;
}
int F_25 ( struct V_3 * V_4 )
{
F_26 ( & V_4 -> V_2 ) ;
return 0 ;
}
