static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_4 ) ;
V_3 |= ( V_5 | V_6 | V_7 ) ;
F_3 ( V_4 , V_3 ) ;
F_2 ( V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_3 ( V_4 , 0x0 ) ;
F_2 ( V_4 ) ;
}
static int F_5 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
struct V_12 * V_13 = V_2 -> V_13 ;
T_1 V_3 ;
V_13 -> V_14 = V_15 ;
V_13 -> V_16 = V_11 ;
V_13 -> V_17 = 0 ;
F_7 ( V_13 -> V_18 ) ;
V_3 = ( ( V_11 -> V_19 ) << 20 ) | V_20 | V_21 ;
F_3 ( V_22 , V_3 ) ;
F_2 ( V_22 ) ;
while ( V_13 -> V_14 != V_23 )
F_8 ( & V_13 -> V_18 ,
10 * V_24 ) ;
return 0 ;
}
static int F_9 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
return 0 ;
}
static int F_10 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
int V_25 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
struct V_12 * V_13 = V_2 -> V_13 ;
int V_26 ;
F_11 ( & V_13 -> V_27 ) ;
F_3 ( V_28 , 0x00008760 ) ;
F_1 ( V_2 ) ;
for ( V_26 = 0 ; V_26 < V_25 ; V_26 ++ ) {
if ( V_11 -> V_19 && V_11 -> V_29 ) {
if ( V_11 -> V_30 & V_31 )
F_5 ( V_9 , V_11 ) ;
else
F_9 ( V_9 , V_11 ) ;
}
V_11 ++ ;
}
F_4 ( V_2 ) ;
F_12 ( & V_13 -> V_27 ) ;
return V_26 ;
}
static T_1 F_13 ( struct V_8 * V_32 )
{
return V_33 | V_34 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
struct V_10 * V_16 = V_13 -> V_16 ;
T_2 * V_29 = V_16 -> V_29 ;
T_1 V_3 ;
int V_26 , V_35 ;
V_35 = V_13 -> V_17 ;
for ( V_26 = 0 ; V_26 < 0x10 ; V_26 ++ ) {
V_3 = F_2 ( V_36 + ( V_26 * 4 ) ) ;
memcpy ( V_29 + ( V_35 + V_26 * 4 ) , & V_3 , 4 ) ;
}
V_13 -> V_17 += ( 0x10 * 4 ) ;
V_3 = F_2 ( V_37 ) ;
F_3 ( V_37 , V_3 | V_6 ) ;
F_2 ( V_37 ) ;
V_3 = F_2 ( V_22 ) ;
F_3 ( V_22 , V_3 | V_38 ) ;
F_2 ( V_22 ) ;
V_13 -> V_14 = V_39 ;
return;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
T_1 V_3 ;
V_3 = F_2 ( V_37 ) ;
F_3 ( V_37 , V_3 | V_7 ) ;
F_2 ( V_37 ) ;
V_3 = F_2 ( V_22 ) ;
F_3 ( V_22 , V_3 & ~ V_21 ) ;
F_2 ( V_22 ) ;
V_13 -> V_14 = V_23 ;
return;
}
static T_3 F_16 ( int V_40 , void * V_41 )
{
struct V_1 * V_2 = V_41 ;
struct V_12 * V_13 = V_2 -> V_13 ;
T_1 V_42 ;
V_42 = F_2 ( V_37 ) ;
if ( V_42 & V_43 ) {
F_3 ( V_37 , V_42 | V_43 ) ;
F_2 ( V_37 ) ;
}
if ( V_42 & V_6 )
F_14 ( V_2 ) ;
if ( V_42 & V_7 )
F_15 ( V_2 ) ;
V_18 ( & V_13 -> V_18 ) ;
return V_44 ;
}
static void F_17 ( void )
{
void T_4 * V_45 ;
unsigned int V_46 = 0xff12c000 ;
int V_47 = 0x1000 ;
T_1 V_3 ;
V_45 = F_18 ( ( V_48 ) V_46 , V_47 ) ;
if ( V_45 == NULL ) {
F_19 ( L_1 ) ;
return;
}
V_3 = F_20 ( V_45 + 0x44 ) ;
F_21 ( L_2 , V_3 ) ;
F_22 ( ( V_3 | 0x00000a00 ) , ( V_45 + 0x44 ) ) ;
V_3 = F_20 ( V_45 + 0x44 ) ;
F_21 ( L_3 , V_3 ) ;
F_23 ( V_45 ) ;
}
int F_24 ( struct V_49 * V_41 )
{
struct V_1 * V_2 ;
struct V_12 * V_13 ;
int V_50 ;
V_2 = F_25 ( V_41 ) ;
V_13 = F_26 ( sizeof( struct V_12 ) , V_51 ) ;
if ( V_13 == NULL ) {
F_19 ( L_4 ) ;
V_50 = - V_52 ;
goto exit;
}
V_13 -> V_9 = & V_53 ;
V_13 -> V_14 = V_15 ;
F_27 ( & V_13 -> V_18 ) ;
F_28 ( & V_13 -> V_27 ) ;
F_29 ( & V_53 , V_2 ) ;
V_2 -> V_13 = V_13 ;
F_17 () ;
V_50 = F_30 ( V_41 -> V_54 , F_16 , V_55 ,
V_53 . V_56 , V_2 ) ;
if ( V_50 ) {
F_19 ( L_5 ) ;
goto V_57;
}
V_50 = F_31 ( & V_53 ) ;
return V_50 ;
V_57:
F_32 ( V_13 ) ;
exit:
return V_50 ;
}
void F_33 ( struct V_49 * V_41 )
{
struct V_1 * V_2 ;
struct V_12 * V_13 ;
V_2 = F_25 ( V_41 ) ;
F_34 ( & V_53 ) ;
V_13 = V_2 -> V_13 ;
F_32 ( V_13 ) ;
F_35 ( V_41 -> V_54 , V_2 ) ;
}
