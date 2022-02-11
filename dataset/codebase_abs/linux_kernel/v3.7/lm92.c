static inline int F_1 ( T_1 V_1 )
{
return V_1 / 8 * 625 / 10 ;
}
static inline T_1 F_2 ( int V_2 )
{
if ( V_2 <= - 60000 )
return - 60000 * 10 / 625 * 8 ;
if ( V_2 >= 160000 )
return 160000 * 10 / 625 * 8 ;
return V_2 * 10 / 625 * 8 ;
}
static inline T_2 F_3 ( T_1 V_1 )
{
return V_1 & 0x0007 ;
}
static struct V_3 * F_4 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_5 ( V_5 ) ;
struct V_3 * V_8 = F_6 ( V_7 ) ;
F_7 ( & V_8 -> V_9 ) ;
if ( F_8 ( V_10 , V_8 -> V_11 + V_12 )
|| ! V_8 -> V_13 ) {
F_9 ( & V_7 -> V_5 , L_1 ) ;
V_8 -> V_14 = F_10 ( V_7 ,
V_15 ) ;
V_8 -> V_16 = F_10 ( V_7 ,
V_17 ) ;
V_8 -> V_18 = F_10 ( V_7 ,
V_19 ) ;
V_8 -> V_20 = F_10 ( V_7 ,
V_21 ) ;
V_8 -> V_22 = F_10 ( V_7 ,
V_23 ) ;
V_8 -> V_11 = V_10 ;
V_8 -> V_13 = 1 ;
}
F_11 ( & V_8 -> V_9 ) ;
return V_8 ;
}
static T_3 F_12 ( struct V_4 * V_5 ,
struct V_24 * V_25 , char * V_26 )
{
struct V_3 * V_8 = F_4 ( V_5 ) ;
return sprintf ( V_26 , L_2 , F_1 ( V_8 -> V_18 )
- F_1 ( V_8 -> V_16 ) ) ;
}
static T_3 F_13 ( struct V_4 * V_5 ,
struct V_24 * V_25 , char * V_26 )
{
struct V_3 * V_8 = F_4 ( V_5 ) ;
return sprintf ( V_26 , L_2 , F_1 ( V_8 -> V_22 )
- F_1 ( V_8 -> V_16 ) ) ;
}
static T_3 F_14 ( struct V_4 * V_5 ,
struct V_24 * V_25 , char * V_26 )
{
struct V_3 * V_8 = F_4 ( V_5 ) ;
return sprintf ( V_26 , L_2 , F_1 ( V_8 -> V_20 )
+ F_1 ( V_8 -> V_16 ) ) ;
}
static T_3 F_15 ( struct V_4 * V_5 ,
struct V_24 * V_25 ,
const char * V_26 , T_4 V_27 )
{
struct V_6 * V_7 = F_5 ( V_5 ) ;
struct V_3 * V_8 = F_6 ( V_7 ) ;
long V_2 ;
int V_28 ;
V_28 = F_16 ( V_26 , 10 , & V_2 ) ;
if ( V_28 )
return V_28 ;
F_7 ( & V_8 -> V_9 ) ;
V_8 -> V_16 = F_1 ( V_8 -> V_18 ) - V_2 ;
F_17 ( V_7 , V_17 ,
F_2 ( V_8 -> V_16 ) ) ;
F_11 ( & V_8 -> V_9 ) ;
return V_27 ;
}
static T_3 F_18 ( struct V_4 * V_5 , struct V_24 * V_25 ,
char * V_26 )
{
struct V_3 * V_8 = F_4 ( V_5 ) ;
return sprintf ( V_26 , L_2 , F_3 ( V_8 -> V_14 ) ) ;
}
static T_3 F_19 ( struct V_4 * V_5 , struct V_24 * V_25 ,
char * V_26 )
{
int V_29 = F_20 ( V_25 ) -> V_30 ;
struct V_3 * V_8 = F_4 ( V_5 ) ;
return sprintf ( V_26 , L_2 , ( V_8 -> V_14 >> V_29 ) & 1 ) ;
}
static void F_21 ( struct V_6 * V_7 )
{
T_2 V_31 ;
V_31 = F_22 ( V_7 , V_32 ) ;
if ( V_31 & 0x01 )
F_23 ( V_7 , V_32 ,
V_31 & 0xFE ) ;
}
static int F_24 ( struct V_6 * V_7 )
{
T_5 V_33 , V_34 , V_35 , V_36 ;
T_2 V_37 ;
int V_38 ;
V_33 = F_25 ( V_7 , V_21 ) ;
if ( F_25 ( V_7 , V_39 ) != V_33 )
return 0 ;
V_34 = F_25 ( V_7 , V_23 ) ;
if ( F_25 ( V_7 , V_39 ) != V_34 )
return 0 ;
if ( ( V_33 & 0x7f00 ) || ( V_34 & 0x7f00 ) )
return 0 ;
V_35 = F_25 ( V_7 , V_17 ) ;
V_36 = F_25 ( V_7 , V_19 ) ;
if ( ( V_35 & 0x7f00 ) || ( V_36 & 0x7f00 ) )
return 0 ;
V_37 = F_22 ( V_7 , V_32 ) ;
for ( V_38 = 16 ; V_38 < 96 ; V_38 *= 2 ) {
if ( V_35 != F_25 ( V_7 ,
V_17 + V_38 - 16 )
|| V_36 != F_25 ( V_7 ,
V_19 + V_38 )
|| V_33 != F_25 ( V_7 ,
V_21 + V_38 + 16 )
|| V_34 != F_25 ( V_7 ,
V_23 + V_38 + 32 )
|| V_37 != F_22 ( V_7 ,
V_32 + V_38 ) )
return 0 ;
}
return 1 ;
}
static int F_26 ( struct V_6 * V_40 ,
struct V_41 * V_42 )
{
struct V_43 * V_44 = V_40 -> V_44 ;
T_2 V_31 ;
T_5 V_45 ;
if ( ! F_27 ( V_44 , V_46
| V_47 ) )
return - V_48 ;
V_31 = F_22 ( V_40 , V_32 ) ;
V_45 = F_25 ( V_40 , V_39 ) ;
if ( ( V_31 & 0xe0 ) == 0x00 && V_45 == 0x0180 )
F_28 ( L_3 ) ;
else if ( F_24 ( V_40 ) )
F_28 ( L_4 ) ;
else
return - V_48 ;
F_29 ( V_42 -> type , L_5 , V_49 ) ;
return 0 ;
}
static int F_30 ( struct V_6 * V_40 ,
const struct V_50 * V_51 )
{
struct V_3 * V_8 ;
int V_28 ;
V_8 = F_31 ( & V_40 -> V_5 , sizeof( struct V_3 ) ,
V_52 ) ;
if ( ! V_8 )
return - V_53 ;
F_32 ( V_40 , V_8 ) ;
V_8 -> V_13 = 0 ;
F_33 ( & V_8 -> V_9 ) ;
F_21 ( V_40 ) ;
V_28 = F_34 ( & V_40 -> V_5 . V_54 , & V_55 ) ;
if ( V_28 )
return V_28 ;
V_8 -> V_56 = F_35 ( & V_40 -> V_5 ) ;
if ( F_36 ( V_8 -> V_56 ) ) {
V_28 = F_37 ( V_8 -> V_56 ) ;
goto V_57;
}
return 0 ;
V_57:
F_38 ( & V_40 -> V_5 . V_54 , & V_55 ) ;
return V_28 ;
}
static int F_39 ( struct V_6 * V_7 )
{
struct V_3 * V_8 = F_6 ( V_7 ) ;
F_40 ( V_8 -> V_56 ) ;
F_38 ( & V_7 -> V_5 . V_54 , & V_55 ) ;
return 0 ;
}
