static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) ) ;
}
static int F_4 ( struct V_4 T_1 * V_5 , int V_6 )
{
int V_7 = 0 ;
F_5 ( V_6 , & V_5 -> V_8 ) ;
while ( F_6 ( & V_5 -> V_8 ) & V_9 ) {
if ( V_7 ++ > 200 * 100 )
return - V_10 ;
F_7 () ;
}
return 0 ;
}
static int F_8 ( struct V_2 * V_3 , unsigned long V_11 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
struct V_4 T_1 * V_5 = V_12 -> V_5 ;
int V_7 , V_13 ;
unsigned char V_14 [ 6 ] ;
V_14 [ 0 ] = 0 ;
V_14 [ 1 ] = 0 ;
V_14 [ 2 ] = V_11 ;
V_14 [ 3 ] = V_11 >> 8 ;
V_14 [ 4 ] = V_11 >> 16 ;
V_14 [ 5 ] = V_11 >> 24 ;
F_9 ( & V_12 -> V_15 ) ;
F_5 ( 0 , & V_5 -> V_16 ) ;
for ( V_7 = 0 ; V_7 < 6 ; V_7 ++ )
F_5 ( V_14 [ V_7 ] , & V_5 -> V_17 ) ;
V_13 = F_4 ( V_5 ,
V_18 |
( F_6 ( & V_5 -> V_8 ) & V_19 ) ) ;
F_10 ( & V_12 -> V_15 ) ;
return V_13 ;
}
static int F_11 ( struct V_2 * V_3 , struct V_20 * V_21 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
struct V_4 T_1 * V_5 = V_12 -> V_5 ;
int V_7 , V_13 ;
unsigned long V_22 ;
unsigned char V_14 [ 6 ] ;
F_9 ( & V_12 -> V_15 ) ;
V_13 = F_4 ( V_5 ,
V_23 |
( F_6 ( & V_5 -> V_8 ) & V_19 ) ) ;
if ( V_13 ) {
F_10 ( & V_12 -> V_15 ) ;
return V_13 ;
}
F_5 ( 2 , & V_5 -> V_16 ) ;
for ( V_7 = 2 ; V_7 < 6 ; V_7 ++ )
V_14 [ V_7 ] = F_6 ( & V_5 -> V_17 ) ;
F_10 ( & V_12 -> V_15 ) ;
V_22 = ( V_14 [ 5 ] << 24 ) | ( V_14 [ 4 ] << 16 ) | ( V_14 [ 3 ] << 8 ) | V_14 [ 2 ] ;
F_12 ( V_22 , V_21 ) ;
return F_13 ( V_21 ) ;
}
static int F_14 ( struct V_2 * V_3 , struct V_24 * V_25 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
struct V_4 T_1 * V_5 = V_12 -> V_5 ;
int V_7 , V_13 ;
unsigned long V_22 ;
unsigned char V_14 [ 6 ] ;
if ( V_25 -> time . V_26 < 0 ||
V_25 -> time . V_27 < 0 ||
V_25 -> time . V_28 < 0 ||
V_25 -> time . V_29 < 0 ||
V_25 -> time . V_30 < 0 ||
V_25 -> time . V_31 < 0 )
return - V_32 ;
F_15 ( & V_25 -> time , & V_22 ) ;
V_14 [ 0 ] = 0 ;
V_14 [ 1 ] = 0 ;
V_14 [ 2 ] = V_22 ;
V_14 [ 3 ] = V_22 >> 8 ;
V_14 [ 4 ] = V_22 >> 16 ;
V_14 [ 5 ] = V_22 >> 24 ;
F_9 ( & V_12 -> V_15 ) ;
F_5 ( 0 , & V_5 -> V_16 ) ;
for ( V_7 = 0 ; V_7 < 6 ; V_7 ++ )
F_5 ( V_14 [ V_7 ] , & V_5 -> V_17 ) ;
V_13 = F_4 ( V_5 , V_33 |
( V_25 -> V_34 ? V_19 : 0 ) ) ;
F_10 ( & V_12 -> V_15 ) ;
return V_13 ;
}
static int F_16 ( struct V_2 * V_3 , struct V_24 * V_25 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
struct V_4 T_1 * V_5 = V_12 -> V_5 ;
int V_7 , V_13 ;
unsigned long V_22 ;
unsigned char V_14 [ 6 ] ;
T_2 V_8 ;
F_9 ( & V_12 -> V_15 ) ;
V_13 = F_4 ( V_5 ,
V_35 |
( F_6 ( & V_5 -> V_8 ) & V_19 ) ) ;
if ( V_13 ) {
F_10 ( & V_12 -> V_15 ) ;
return V_13 ;
}
F_5 ( 2 , & V_5 -> V_16 ) ;
for ( V_7 = 2 ; V_7 < 6 ; V_7 ++ )
V_14 [ V_7 ] = F_6 ( & V_5 -> V_17 ) ;
V_8 = F_6 ( & V_5 -> V_8 ) ;
V_25 -> V_34 = ( V_8 & V_19 ) ? 1 : 0 ;
V_25 -> V_36 = ( V_8 & V_37 ) ? 1 : 0 ;
F_10 ( & V_12 -> V_15 ) ;
V_22 = ( V_14 [ 5 ] << 24 ) | ( V_14 [ 4 ] << 16 ) | ( V_14 [ 3 ] << 8 ) | V_14 [ 2 ] ;
F_12 ( V_22 , & V_25 -> time ) ;
return F_13 ( & V_25 -> time ) ;
}
static int F_17 ( struct V_2 * V_3 , unsigned int V_34 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
F_9 ( & V_12 -> V_15 ) ;
F_4 ( V_12 -> V_5 ,
V_38 |
( V_34 ? V_19 : 0 ) ) ;
F_10 ( & V_12 -> V_15 ) ;
return 0 ;
}
static T_3 F_18 ( int V_39 , void * V_40 )
{
struct V_1 * V_12 = F_1 ( V_40 ) ;
struct V_4 T_1 * V_5 = V_12 -> V_5 ;
unsigned long V_41 = V_42 ;
F_19 ( & V_12 -> V_15 ) ;
if ( F_6 ( & V_5 -> V_8 ) & V_37 ) {
V_41 |= V_43 ;
F_4 ( V_5 , V_38 ) ;
}
F_20 ( & V_12 -> V_15 ) ;
F_21 ( V_12 -> V_44 , 1 , V_41 ) ;
return V_45 ;
}
static T_4 F_22 ( struct V_46 * V_47 , struct V_48 * V_49 ,
struct V_50 * V_51 ,
char * V_14 , T_5 V_52 , T_6 V_53 )
{
struct V_2 * V_3 = F_23 ( V_49 , struct V_2 , V_49 ) ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
struct V_4 T_1 * V_5 = V_12 -> V_5 ;
T_4 V_54 ;
F_9 ( & V_12 -> V_15 ) ;
for ( V_54 = 0 ; V_54 < V_53 ; V_54 ++ ) {
F_5 ( V_52 ++ , & V_5 -> V_16 ) ;
* V_14 ++ = F_6 ( & V_5 -> V_17 ) ;
}
F_10 ( & V_12 -> V_15 ) ;
return V_54 ;
}
static T_4 F_24 ( struct V_46 * V_47 , struct V_48 * V_49 ,
struct V_50 * V_51 ,
char * V_14 , T_5 V_52 , T_6 V_53 )
{
struct V_2 * V_3 = F_23 ( V_49 , struct V_2 , V_49 ) ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
struct V_4 T_1 * V_5 = V_12 -> V_5 ;
T_4 V_54 ;
F_9 ( & V_12 -> V_15 ) ;
for ( V_54 = 0 ; V_54 < V_53 ; V_54 ++ ) {
F_5 ( V_52 ++ , & V_5 -> V_16 ) ;
F_5 ( * V_14 ++ , & V_5 -> V_17 ) ;
}
F_10 ( & V_12 -> V_15 ) ;
return V_54 ;
}
static int T_7 F_25 ( struct V_55 * V_56 )
{
struct V_57 * V_44 ;
struct V_1 * V_12 ;
struct V_58 * V_59 ;
int V_39 , V_13 ;
V_39 = F_26 ( V_56 , 0 ) ;
if ( V_39 < 0 )
return - V_60 ;
V_12 = F_27 ( & V_56 -> V_3 , sizeof( * V_12 ) , V_61 ) ;
if ( ! V_12 )
return - V_62 ;
F_28 ( V_56 , V_12 ) ;
V_59 = F_29 ( V_56 , V_63 , 0 ) ;
V_12 -> V_5 = F_30 ( & V_56 -> V_3 , V_59 ) ;
if ( F_31 ( V_12 -> V_5 ) )
return F_32 ( V_12 -> V_5 ) ;
F_33 ( & V_12 -> V_15 ) ;
F_4 ( V_12 -> V_5 , V_38 ) ;
if ( F_34 ( & V_56 -> V_3 , V_39 , F_18 ,
0 , V_56 -> V_64 , & V_56 -> V_3 ) < 0 )
return - V_10 ;
V_44 = F_35 ( & V_56 -> V_3 , V_56 -> V_64 ,
& V_65 , V_66 ) ;
if ( F_31 ( V_44 ) )
return F_32 ( V_44 ) ;
V_12 -> V_44 = V_44 ;
V_13 = F_36 ( & V_56 -> V_3 . V_49 , & V_67 ) ;
return V_13 ;
}
static int T_8 F_37 ( struct V_55 * V_56 )
{
struct V_1 * V_12 = F_2 ( V_56 ) ;
F_38 ( & V_56 -> V_3 . V_49 , & V_67 ) ;
F_9 ( & V_12 -> V_15 ) ;
F_4 ( V_12 -> V_5 , V_38 ) ;
F_10 ( & V_12 -> V_15 ) ;
return 0 ;
}
