static void F_1 ( struct V_1 * V_2 , const char * V_3 , T_1 * V_4 ,
int V_5 )
{
#ifdef F_2
int V_6 ;
F_3 ( V_2 , L_1 , V_3 ) ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ )
F_4 ( V_2 , L_2 , V_4 [ V_6 ] ) ;
#endif
}
static int F_5 ( struct V_7 * V_8 ,
int V_9 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_13 V_14 ;
struct V_15 V_16 ;
T_1 * V_4 , * V_17 ;
int V_18 ;
unsigned long V_19 ;
int V_20 ;
V_19 = V_21 + F_6 ( V_22 ) ;
do {
memset ( & V_14 , '\0' , sizeof( V_14 ) ) ;
V_14 . V_23 = 1 ;
V_14 . V_24 = V_4 = V_8 -> V_25 ;
V_14 . V_5 = V_26 ;
F_7 ( & V_16 ) ;
F_8 ( & V_14 , & V_16 ) ;
V_18 = F_9 ( V_11 -> V_27 , & V_16 ) ;
if ( V_18 < 0 ) {
F_10 ( V_8 -> V_2 , L_3 , V_18 ) ;
return V_18 ;
}
for ( V_17 = V_4 + V_26 ; V_4 != V_17 ; V_4 ++ ) {
if ( * V_4 == V_28 ) {
F_3 ( V_8 -> V_2 , L_4 ,
V_4 - V_8 -> V_25 ) ;
break;
}
}
if ( F_11 ( V_21 , V_19 ) ) {
F_12 ( V_8 -> V_2 , L_5 ) ;
return - V_29 ;
}
} while ( V_4 == V_17 );
V_20 = V_17 - ++ V_4 ;
F_13 ( V_20 < 0 || V_20 > V_8 -> V_30 ) ;
V_20 = F_14 ( V_20 , V_9 ) ;
memmove ( V_8 -> V_25 , V_4 , V_20 ) ;
V_4 = V_8 -> V_25 + V_20 ;
F_3 ( V_8 -> V_2 , L_6 ,
V_9 , V_20 ) ;
V_9 -= V_20 ;
while ( V_9 > 0 ) {
V_20 = F_14 ( V_9 , 256 ) ;
F_3 ( V_8 -> V_2 , L_7 ,
V_20 , V_9 , V_4 - V_8 -> V_25 ) ;
memset ( & V_14 , '\0' , sizeof( V_14 ) ) ;
V_14 . V_23 = 1 ;
V_14 . V_24 = V_4 ;
V_14 . V_5 = V_20 ;
F_7 ( & V_16 ) ;
F_8 ( & V_14 , & V_16 ) ;
F_13 ( ( T_1 * ) V_14 . V_24 - V_8 -> V_25 + V_20 >
V_8 -> V_30 ) ;
V_18 = F_9 ( V_11 -> V_27 , & V_16 ) ;
if ( V_18 < 0 ) {
F_10 ( V_8 -> V_2 , L_3 , V_18 ) ;
return V_18 ;
}
F_1 ( V_8 -> V_2 , L_8 , V_4 , V_20 ) ;
V_4 += V_20 ;
V_9 -= V_20 ;
}
F_3 ( V_8 -> V_2 , L_9 , V_4 - V_8 -> V_25 ) ;
return 0 ;
}
static int F_15 ( struct V_7 * V_8 ,
struct V_31 * V_32 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_13 V_14 ;
struct V_15 V_16 ;
int V_6 , V_5 ;
T_1 * V_4 ;
int V_33 ;
int V_18 = 0 , V_34 ;
struct V_35 V_36 ;
V_5 = F_16 ( V_8 , V_32 ) ;
F_3 ( V_8 -> V_2 , L_10 , V_5 ) ;
if ( V_11 -> V_37 ) {
struct V_35 V_36 ;
unsigned long V_38 ;
F_17 ( & V_36 ) ;
V_38 = F_18 ( & V_36 ) - V_11 -> V_37 ;
if ( V_38 < V_39 )
F_19 ( V_38 ) ;
}
F_1 ( V_8 -> V_2 , L_11 , V_8 -> V_40 , V_5 ) ;
memset ( & V_14 , '\0' , sizeof( V_14 ) ) ;
V_14 . V_41 = V_8 -> V_40 ;
V_14 . V_5 = V_5 ;
V_14 . V_23 = 1 ;
F_7 ( & V_16 ) ;
F_8 ( & V_14 , & V_16 ) ;
V_18 = F_9 ( V_11 -> V_27 , & V_16 ) ;
if ( ! V_18 ) {
V_18 = F_5 ( V_8 ,
V_32 -> V_42 + V_43 ) ;
} else {
F_10 ( V_8 -> V_2 , L_3 , V_18 ) ;
}
F_7 ( & V_16 ) ;
V_34 = F_9 ( V_11 -> V_27 , & V_16 ) ;
F_17 ( & V_36 ) ;
V_11 -> V_37 = F_18 ( & V_36 ) ;
if ( ! V_18 )
V_18 = V_34 ;
if ( V_18 < 0 ) {
F_10 ( V_8 -> V_2 , L_3 , V_18 ) ;
return V_18 ;
}
V_4 = V_8 -> V_25 ;
if ( V_4 [ 0 ] ) {
F_12 ( V_8 -> V_2 , L_12 ,
V_32 -> V_44 , V_4 [ 0 ] ) ;
F_1 ( V_8 -> V_2 , L_13 , V_4 , V_5 ) ;
return - V_45 ;
}
V_5 = V_4 [ 1 ] ;
V_33 = V_4 [ 0 ] + V_4 [ 1 ] ;
if ( V_5 > V_32 -> V_42 ) {
F_10 ( V_8 -> V_2 , L_14 ,
V_5 , V_32 -> V_42 ) ;
return - V_46 ;
}
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ ) {
V_33 += V_4 [ V_6 + 2 ] ;
if ( V_32 -> V_42 )
V_32 -> V_47 [ V_6 ] = V_4 [ V_6 + 2 ] ;
}
V_33 &= 0xff ;
F_1 ( V_8 -> V_2 , L_15 , V_4 , V_5 + 3 ) ;
if ( V_33 != V_4 [ V_5 + 2 ] ) {
F_10 ( V_8 -> V_2 ,
L_16 ,
V_33 , V_4 [ V_5 + 2 ] ) ;
return - V_48 ;
}
return 0 ;
}
static int F_20 ( struct V_49 * V_27 )
{
struct V_1 * V_2 = & V_27 -> V_2 ;
struct V_7 * V_8 ;
struct V_10 * V_11 ;
int V_50 ;
V_27 -> V_51 = 8 ;
V_27 -> V_52 = V_53 ;
V_50 = F_21 ( V_27 ) ;
if ( V_50 < 0 )
return V_50 ;
V_11 = F_22 ( V_2 , sizeof( * V_11 ) , V_54 ) ;
if ( V_11 == NULL )
return - V_55 ;
V_11 -> V_27 = V_27 ;
V_8 = F_22 ( V_2 , sizeof( * V_8 ) , V_54 ) ;
if ( ! V_8 )
return - V_55 ;
F_23 ( V_27 , V_8 ) ;
V_8 -> V_3 = L_17 ;
V_8 -> V_2 = V_2 ;
V_8 -> V_12 = V_11 ;
V_8 -> V_56 = V_27 -> V_56 ;
V_8 -> V_57 = F_15 ;
V_8 -> V_58 = V_11 -> V_27 -> V_59 ;
V_8 -> V_60 = F_24 ( & V_11 -> V_27 -> V_2 ) ;
V_8 -> V_61 = & V_11 -> V_27 -> V_2 ;
V_8 -> V_30 = V_62 + V_26 ;
V_8 -> V_63 = V_62 ;
V_50 = F_25 ( V_8 ) ;
if ( V_50 ) {
F_10 ( V_2 , L_18 ) ;
return V_50 ;
}
return 0 ;
}
static int F_26 ( struct V_49 * V_27 )
{
struct V_7 * V_8 ;
V_8 = F_27 ( V_27 ) ;
F_28 ( V_8 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_30 ( V_2 ) ;
return F_31 ( V_8 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_30 ( V_2 ) ;
return F_33 ( V_8 ) ;
}
