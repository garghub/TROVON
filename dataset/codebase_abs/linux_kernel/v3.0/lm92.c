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
V_8 -> V_14 = F_10 ( F_11 ( V_7 ,
V_15 ) ) ;
V_8 -> V_16 = F_10 ( F_11 ( V_7 ,
V_17 ) ) ;
V_8 -> V_18 = F_10 ( F_11 ( V_7 ,
V_19 ) ) ;
V_8 -> V_20 = F_10 ( F_11 ( V_7 ,
V_21 ) ) ;
V_8 -> V_22 = F_10 ( F_11 ( V_7 ,
V_23 ) ) ;
V_8 -> V_11 = V_10 ;
V_8 -> V_13 = 1 ;
}
F_12 ( & V_8 -> V_9 ) ;
return V_8 ;
}
static T_3 F_13 ( struct V_4 * V_5 , struct V_24 * V_25 , char * V_26 )
{
struct V_3 * V_8 = F_4 ( V_5 ) ;
return sprintf ( V_26 , L_2 , F_1 ( V_8 -> V_18 )
- F_1 ( V_8 -> V_16 ) ) ;
}
static T_3 F_14 ( struct V_4 * V_5 , struct V_24 * V_25 , char * V_26 )
{
struct V_3 * V_8 = F_4 ( V_5 ) ;
return sprintf ( V_26 , L_2 , F_1 ( V_8 -> V_22 )
- F_1 ( V_8 -> V_16 ) ) ;
}
static T_3 F_15 ( struct V_4 * V_5 , struct V_24 * V_25 , char * V_26 )
{
struct V_3 * V_8 = F_4 ( V_5 ) ;
return sprintf ( V_26 , L_2 , F_1 ( V_8 -> V_20 )
+ F_1 ( V_8 -> V_16 ) ) ;
}
static T_3 F_16 ( struct V_4 * V_5 , struct V_24 * V_25 , const char * V_26 ,
T_4 V_27 )
{
struct V_6 * V_7 = F_5 ( V_5 ) ;
struct V_3 * V_8 = F_6 ( V_7 ) ;
long V_2 = F_17 ( V_26 , NULL , 10 ) ;
F_7 ( & V_8 -> V_9 ) ;
V_8 -> V_16 = F_1 ( V_8 -> V_18 ) - V_2 ;
F_18 ( V_7 , V_17 ,
F_10 ( F_2 ( V_8 -> V_16 ) ) ) ;
F_12 ( & V_8 -> V_9 ) ;
return V_27 ;
}
static T_3 F_19 ( struct V_4 * V_5 , struct V_24 * V_25 , char * V_26 )
{
struct V_3 * V_8 = F_4 ( V_5 ) ;
return sprintf ( V_26 , L_2 , F_3 ( V_8 -> V_14 ) ) ;
}
static T_3 F_20 ( struct V_4 * V_5 , struct V_24 * V_25 ,
char * V_26 )
{
int V_28 = F_21 ( V_25 ) -> V_29 ;
struct V_3 * V_8 = F_4 ( V_5 ) ;
return sprintf ( V_26 , L_2 , ( V_8 -> V_14 >> V_28 ) & 1 ) ;
}
static void F_22 ( struct V_6 * V_7 )
{
T_2 V_30 ;
V_30 = F_23 ( V_7 , V_31 ) ;
if ( V_30 & 0x01 )
F_24 ( V_7 , V_31 ,
V_30 & 0xFE ) ;
}
static int F_25 ( struct V_6 * V_7 )
{
T_5 V_32 , V_33 , V_34 , V_35 ;
T_2 V_36 ;
int V_37 ;
V_32 = F_11 ( V_7 , V_21 ) ;
if ( F_11 ( V_7 , V_38 ) != V_32 )
return 0 ;
V_33 = F_11 ( V_7 , V_23 ) ;
if ( F_11 ( V_7 , V_38 ) != V_33 )
return 0 ;
if ( ( V_32 & 0x7f00 ) || ( V_33 & 0x7f00 ) )
return 0 ;
V_34 = F_11 ( V_7 , V_17 ) ;
V_35 = F_11 ( V_7 , V_19 ) ;
if ( ( V_34 & 0x7f00 ) || ( V_35 & 0x7f00 ) )
return 0 ;
V_36 = F_23 ( V_7 , V_31 ) ;
for ( V_37 = 16 ; V_37 < 96 ; V_37 *= 2 ) {
if ( V_34 != F_11 ( V_7 ,
V_17 + V_37 - 16 )
|| V_35 != F_11 ( V_7 ,
V_19 + V_37 )
|| V_32 != F_11 ( V_7 ,
V_21 + V_37 + 16 )
|| V_33 != F_11 ( V_7 ,
V_23 + V_37 + 32 )
|| V_36 != F_23 ( V_7 ,
V_31 + V_37 ) )
return 0 ;
}
return 1 ;
}
static int F_26 ( struct V_6 * V_39 ,
struct V_40 * V_41 )
{
struct V_42 * V_43 = V_39 -> V_43 ;
T_2 V_30 ;
T_5 V_44 ;
if ( ! F_27 ( V_43 , V_45
| V_46 ) )
return - V_47 ;
V_30 = F_23 ( V_39 , V_31 ) ;
V_44 = F_11 ( V_39 , V_38 ) ;
if ( ( V_30 & 0xe0 ) == 0x00 && V_44 == 0x0180 )
F_28 ( L_3 ) ;
else if ( F_25 ( V_39 ) )
F_28 ( L_4 ) ;
else
return - V_47 ;
F_29 ( V_41 -> type , L_5 , V_48 ) ;
return 0 ;
}
static int F_30 ( struct V_6 * V_39 ,
const struct V_49 * V_50 )
{
struct V_3 * V_8 ;
int V_51 ;
V_8 = F_31 ( sizeof( struct V_3 ) , V_52 ) ;
if ( ! V_8 ) {
V_51 = - V_53 ;
goto exit;
}
F_32 ( V_39 , V_8 ) ;
V_8 -> V_13 = 0 ;
F_33 ( & V_8 -> V_9 ) ;
F_22 ( V_39 ) ;
if ( ( V_51 = F_34 ( & V_39 -> V_5 . V_54 , & V_55 ) ) )
goto V_56;
V_8 -> V_57 = F_35 ( & V_39 -> V_5 ) ;
if ( F_36 ( V_8 -> V_57 ) ) {
V_51 = F_37 ( V_8 -> V_57 ) ;
goto V_58;
}
return 0 ;
V_58:
F_38 ( & V_39 -> V_5 . V_54 , & V_55 ) ;
V_56:
F_39 ( V_8 ) ;
exit:
return V_51 ;
}
static int F_40 ( struct V_6 * V_7 )
{
struct V_3 * V_8 = F_6 ( V_7 ) ;
F_41 ( V_8 -> V_57 ) ;
F_38 ( & V_7 -> V_5 . V_54 , & V_55 ) ;
F_39 ( V_8 ) ;
return 0 ;
}
static int T_6 F_42 ( void )
{
return F_43 ( & V_59 ) ;
}
static void T_7 F_44 ( void )
{
F_45 ( & V_59 ) ;
}
