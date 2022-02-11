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
F_14 ( V_4 , V_22 ,
V_4 -> V_23 . V_24 ) ;
F_14 ( V_4 , V_25 , V_16 -> V_26 << 1 ) ;
F_13 ( 4 , L_2 , V_16 -> V_26 ) ;
if ( V_16 -> V_27 == 0 ) {
F_14 ( V_4 , V_28 ,
V_29 ) ;
if ( ! F_11 ( V_2 ) )
return - V_30 ;
if ( F_4 ( V_2 ) )
return - V_30 ;
return 0 ;
}
for ( V_18 = 0 ; V_18 < V_16 -> V_27 ; ) {
F_13 ( 4 , L_3 , V_16 -> V_31 [ V_18 ] ) ;
F_14 ( V_4 , V_32 , V_16 -> V_31 [ V_18 ] ) ;
V_19 ++ ;
V_18 ++ ;
if ( ( V_19 >= 4 ) || ( V_18 >= V_16 -> V_27 ) ) {
if ( V_18 < V_16 -> V_27 )
F_14 ( V_4 , V_28 ,
V_33 |
V_34 ) ;
else
F_14 ( V_4 , V_28 ,
V_33 ) ;
V_19 = 0 ;
if ( ! F_9 ( V_2 ) )
return - V_30 ;
}
}
if ( ! F_11 ( V_2 ) )
return - V_30 ;
F_13 ( 4 , L_4 ) ;
return V_16 -> V_27 ;
}
static int F_15 ( struct V_1 * V_2 ,
const struct V_15 * V_16 , int V_35 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_18 ;
F_13 ( 4 , L_1 , V_20 ) ;
F_14 ( V_4 , V_21 , 0x01 ) ;
F_14 ( V_4 , V_22 ,
V_4 -> V_23 . V_24 ) ;
F_14 ( V_4 , V_25 , V_16 -> V_26 << 1 ) ;
F_13 ( 4 , L_5 ) ;
if ( V_16 -> V_27 == 0 ) {
F_14 ( V_4 , V_28 ,
V_29 ) ;
if ( F_4 ( V_2 ) )
return - V_30 ;
return 0 ;
}
for ( V_18 = 0 ; V_18 < V_16 -> V_27 ; ) {
V_18 ++ ;
if ( V_18 < V_16 -> V_27 )
F_14 ( V_4 , V_28 ,
V_29 |
V_34 ) ;
else
F_14 ( V_4 , V_28 ,
V_29 ) ;
if ( ! F_7 ( V_2 ) )
return - V_30 ;
V_16 -> V_31 [ V_18 - 1 ] = F_2 ( V_4 , V_36 ) &
0xff ;
F_13 ( 4 , L_3 , V_16 -> V_31 [ V_18 - 1 ] ) ;
}
if ( ! F_11 ( V_2 ) )
return - V_30 ;
F_13 ( 4 , L_4 ) ;
return V_16 -> V_27 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_15 * V_37 , int V_38 )
{
int V_18 , V_39 = 0 ;
F_13 ( 4 , L_6 , V_20 , V_38 ) ;
for ( V_18 = 0 ; V_18 < V_38 ; V_18 ++ ) {
F_13 ( 4 , L_7 ,
V_20 , V_38 , V_37 [ V_18 ] . V_26 , V_37 [ V_18 ] . V_27 ) ;
if ( V_37 [ V_18 ] . V_40 & V_41 ) {
V_39 = F_15 ( V_2 , & V_37 [ V_18 ] , 0 ) ;
} else if ( V_18 + 1 < V_38 && ( V_37 [ V_18 + 1 ] . V_40 & V_41 ) &&
V_37 [ V_18 ] . V_26 == V_37 [ V_18 + 1 ] . V_26 ) {
V_39 = F_12 ( V_2 , & V_37 [ V_18 ] ,
V_37 [ V_18 + 1 ] . V_27 ) ;
if ( V_39 < 0 )
goto V_42;
V_18 ++ ;
V_39 = F_15 ( V_2 , & V_37 [ V_18 ] , 1 ) ;
} else {
V_39 = F_12 ( V_2 , & V_37 [ V_18 ] , 0 ) ;
}
if ( V_39 < 0 )
goto V_42;
}
return V_38 ;
V_42:
return V_39 ;
}
static T_1 F_17 ( struct V_1 * V_43 )
{
return V_44 | V_45 ;
}
static void F_18 ( char * V_46 , struct V_47 * V_48 )
{
unsigned char V_31 ;
int V_18 , V_49 ;
for ( V_18 = 0 ; V_18 < 128 ; V_18 ++ ) {
V_48 -> V_26 = V_18 ;
V_49 = F_19 ( V_48 , & V_31 , 0 ) ;
if ( V_49 < 0 )
continue;
F_20 ( V_50 L_8 ,
V_46 , V_18 << 1 , V_51 [ V_18 ] ? V_51 [ V_18 ] : L_9 ) ;
}
}
int F_21 ( struct V_3 * V_4 )
{
F_13 ( 1 , L_1 , V_20 ) ;
memcpy ( & V_4 -> V_2 , & V_52 ,
sizeof( V_4 -> V_2 ) ) ;
memcpy ( & V_4 -> V_53 , & V_54 ,
sizeof( V_4 -> V_53 ) ) ;
memcpy ( & V_4 -> V_47 , & V_55 ,
sizeof( V_4 -> V_47 ) ) ;
V_4 -> V_2 . V_4 . V_56 = & V_4 -> V_57 -> V_4 ;
F_22 ( V_4 -> V_2 . V_46 , V_58 ,
sizeof( V_4 -> V_2 . V_46 ) ) ;
V_4 -> V_2 . V_59 = & V_4 -> V_53 ;
V_4 -> V_2 . V_5 = V_4 ;
F_23 ( & V_4 -> V_2 , & V_4 -> V_60 ) ;
F_24 ( & V_4 -> V_2 ) ;
V_4 -> V_47 . V_61 = & V_4 -> V_2 ;
if ( 0 == V_4 -> V_62 ) {
F_20 ( V_50 L_10 , V_58 ) ;
if ( V_63 )
F_18 ( V_58 , & V_4 -> V_47 ) ;
} else
F_20 ( V_50 L_11 , V_58 ) ;
return V_4 -> V_62 ;
}
int F_25 ( struct V_3 * V_4 )
{
F_26 ( & V_4 -> V_2 ) ;
return 0 ;
}
