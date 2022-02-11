static inline int F_1 ( T_1 V_1 )
{
return V_1 / 8 * 625 / 10 ;
}
static inline T_1 F_2 ( long V_2 )
{
V_2 = F_3 ( V_2 , - 60000 , 160000 ) ;
return V_2 * 10 / 625 * 8 ;
}
static inline T_2 F_4 ( T_1 V_1 )
{
return V_1 & 0x0007 ;
}
static struct V_3 * F_5 ( struct V_4 * V_5 )
{
struct V_3 * V_6 = F_6 ( V_5 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_9 ;
F_7 ( & V_6 -> V_10 ) ;
if ( F_8 ( V_11 , V_6 -> V_12 + V_13 )
|| ! V_6 -> V_14 ) {
F_9 ( & V_8 -> V_5 , L_1 ) ;
for ( V_9 = 0 ; V_9 < V_15 ; V_9 ++ ) {
V_6 -> V_16 [ V_9 ] =
F_10 ( V_8 , V_17 [ V_9 ] ) ;
}
V_6 -> V_12 = V_11 ;
V_6 -> V_14 = 1 ;
}
F_11 ( & V_6 -> V_10 ) ;
return V_6 ;
}
static T_3 F_12 ( struct V_4 * V_5 , struct V_18 * V_19 ,
char * V_20 )
{
struct V_21 * V_22 = F_13 ( V_19 ) ;
struct V_3 * V_6 = F_5 ( V_5 ) ;
return sprintf ( V_20 , L_2 , F_1 ( V_6 -> V_16 [ V_22 -> V_23 ] ) ) ;
}
static T_3 F_14 ( struct V_4 * V_5 , struct V_18 * V_19 ,
const char * V_20 , T_4 V_24 )
{
struct V_21 * V_22 = F_13 ( V_19 ) ;
struct V_3 * V_6 = F_6 ( V_5 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_25 = V_22 -> V_23 ;
long V_2 ;
int V_26 ;
V_26 = F_15 ( V_20 , 10 , & V_2 ) ;
if ( V_26 )
return V_26 ;
F_7 ( & V_6 -> V_10 ) ;
V_6 -> V_16 [ V_25 ] = F_2 ( V_2 ) ;
F_16 ( V_8 , V_17 [ V_25 ] , V_6 -> V_16 [ V_25 ] ) ;
F_11 ( & V_6 -> V_10 ) ;
return V_24 ;
}
static T_3 F_17 ( struct V_4 * V_5 ,
struct V_18 * V_19 , char * V_20 )
{
struct V_21 * V_22 = F_13 ( V_19 ) ;
struct V_3 * V_6 = F_5 ( V_5 ) ;
return sprintf ( V_20 , L_2 , F_1 ( V_6 -> V_16 [ V_22 -> V_23 ] )
- F_1 ( V_6 -> V_16 [ V_27 ] ) ) ;
}
static T_3 F_18 ( struct V_4 * V_5 ,
struct V_18 * V_22 , char * V_20 )
{
struct V_3 * V_6 = F_5 ( V_5 ) ;
return sprintf ( V_20 , L_2 , F_1 ( V_6 -> V_16 [ V_28 ] )
+ F_1 ( V_6 -> V_16 [ V_27 ] ) ) ;
}
static T_3 F_19 ( struct V_4 * V_5 ,
struct V_18 * V_19 ,
const char * V_20 , T_4 V_24 )
{
struct V_21 * V_22 = F_13 ( V_19 ) ;
struct V_3 * V_6 = F_6 ( V_5 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
long V_2 ;
int V_26 ;
V_26 = F_15 ( V_20 , 10 , & V_2 ) ;
if ( V_26 )
return V_26 ;
V_2 = F_3 ( V_2 , - 120000 , 220000 ) ;
F_7 ( & V_6 -> V_10 ) ;
V_6 -> V_16 [ V_27 ] =
F_2 ( F_1 ( V_6 -> V_16 [ V_22 -> V_23 ] ) - V_2 ) ;
F_16 ( V_8 , V_29 ,
V_6 -> V_16 [ V_27 ] ) ;
F_11 ( & V_6 -> V_10 ) ;
return V_24 ;
}
static T_3 F_20 ( struct V_4 * V_5 , struct V_18 * V_22 ,
char * V_20 )
{
struct V_3 * V_6 = F_5 ( V_5 ) ;
return sprintf ( V_20 , L_2 , F_4 ( V_6 -> V_16 [ V_30 ] ) ) ;
}
static T_3 F_21 ( struct V_4 * V_5 , struct V_18 * V_22 ,
char * V_20 )
{
int V_31 = F_13 ( V_22 ) -> V_23 ;
struct V_3 * V_6 = F_5 ( V_5 ) ;
return sprintf ( V_20 , L_2 , ( V_6 -> V_16 [ V_30 ] >> V_31 ) & 1 ) ;
}
static void F_22 ( struct V_7 * V_8 )
{
T_2 V_32 ;
V_32 = F_23 ( V_8 , V_33 ) ;
if ( V_32 & 0x01 )
F_24 ( V_8 , V_33 ,
V_32 & 0xFE ) ;
}
static int F_25 ( struct V_7 * V_8 )
{
T_5 V_34 , V_35 , V_36 , V_37 ;
T_2 V_38 ;
int V_9 ;
V_34 = F_26 ( V_8 , V_39 ) ;
if ( F_26 ( V_8 , V_40 ) != V_34 )
return 0 ;
V_35 = F_26 ( V_8 , V_41 ) ;
if ( F_26 ( V_8 , V_40 ) != V_35 )
return 0 ;
if ( ( V_34 & 0x7f00 ) || ( V_35 & 0x7f00 ) )
return 0 ;
V_36 = F_26 ( V_8 , V_29 ) ;
V_37 = F_26 ( V_8 , V_42 ) ;
if ( ( V_36 & 0x7f00 ) || ( V_37 & 0x7f00 ) )
return 0 ;
V_38 = F_23 ( V_8 , V_33 ) ;
for ( V_9 = 16 ; V_9 < 96 ; V_9 *= 2 ) {
if ( V_36 != F_26 ( V_8 ,
V_29 + V_9 - 16 )
|| V_37 != F_26 ( V_8 ,
V_42 + V_9 )
|| V_34 != F_26 ( V_8 ,
V_39 + V_9 + 16 )
|| V_35 != F_26 ( V_8 ,
V_41 + V_9 + 32 )
|| V_38 != F_23 ( V_8 ,
V_33 + V_9 ) )
return 0 ;
}
return 1 ;
}
static int F_27 ( struct V_7 * V_43 ,
struct V_44 * V_45 )
{
struct V_46 * V_47 = V_43 -> V_47 ;
T_2 V_32 ;
T_5 V_48 ;
if ( ! F_28 ( V_47 , V_49
| V_50 ) )
return - V_51 ;
V_32 = F_23 ( V_43 , V_33 ) ;
V_48 = F_26 ( V_43 , V_40 ) ;
if ( ( V_32 & 0xe0 ) == 0x00 && V_48 == 0x0180 )
F_29 ( L_3 ) ;
else if ( F_25 ( V_43 ) )
F_29 ( L_4 ) ;
else
return - V_51 ;
F_30 ( V_45 -> type , L_5 , V_52 ) ;
return 0 ;
}
static int F_31 ( struct V_7 * V_43 ,
const struct V_53 * V_54 )
{
struct V_4 * V_55 ;
struct V_3 * V_6 ;
V_6 = F_32 ( & V_43 -> V_5 , sizeof( struct V_3 ) ,
V_56 ) ;
if ( ! V_6 )
return - V_57 ;
V_6 -> V_8 = V_43 ;
F_33 ( & V_6 -> V_10 ) ;
F_22 ( V_43 ) ;
V_55 = F_34 ( & V_43 -> V_5 ,
V_43 -> V_58 ,
V_6 , V_59 ) ;
return F_35 ( V_55 ) ;
}
