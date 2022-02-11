static unsigned long F_1 ( struct V_1 * V_2 )
{
unsigned short V_3 , V_4 , V_5 ;
unsigned char V_6 , V_7 ;
V_6 = F_2 ( V_2 -> V_8 + V_9 ) & V_2 -> V_10 ;
do {
V_7 = V_6 ;
V_3 = F_3 ( V_2 -> V_11 + V_12 ) ;
V_4 = F_3 ( V_2 -> V_11 + V_12 ) ;
V_5 = F_3 ( V_2 -> V_11 + V_12 ) ;
V_6 = F_2 ( V_2 -> V_8 + V_9 ) & V_2 -> V_10 ;
} while ( F_4 ( ( V_6 != V_7 ) || ( V_3 > V_4 && V_3 < V_5 )
|| ( V_4 > V_5 && V_4 < V_3 ) || ( V_5 > V_3 && V_5 < V_4 ) ) );
if ( F_5 ( ! V_6 ) )
return V_4 ;
else
return V_4 + 0x10000 ;
}
static T_1 F_6 ( int V_13 , void * V_14 )
{
struct V_1 * V_2 = (struct V_1 * ) V_14 ;
F_7 ( V_2 -> V_10 , V_2 -> V_8 + V_9 ) ;
V_2 -> V_15 += 0x10000 ;
return V_16 ;
}
static inline struct V_1 * F_8 ( struct V_17 * V_18 )
{
return F_9 ( V_18 , struct V_1 , V_18 ) ;
}
static T_2 F_10 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_8 ( V_18 ) ;
unsigned long V_19 , V_20 ;
V_20 = V_2 -> V_15 ;
V_19 = F_1 ( V_2 ) ;
return V_20 + V_19 ;
}
static int F_11 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_8 ( V_18 ) ;
F_12 ( V_2 -> V_21 ) ;
V_2 -> V_15 = 0 ;
F_13 ( 0x0000 , V_2 -> V_11 + V_12 ) ;
F_14 ( 0x83 , V_2 -> V_11 + V_22 ) ;
F_15 ( V_2 -> V_23 , V_2 -> V_8 + V_9 ) ;
F_15 ( V_2 -> V_24 , V_2 -> V_8 + V_25 ) ;
V_2 -> V_21 = true ;
return 0 ;
}
static void F_16 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_8 ( V_18 ) ;
F_12 ( ! V_2 -> V_21 ) ;
F_7 ( V_2 -> V_23 , V_2 -> V_8 + V_9 ) ;
F_7 ( V_2 -> V_24 , V_2 -> V_8 + V_25 ) ;
V_2 -> V_21 = false ;
}
static void T_3 F_17 ( struct V_26 * V_27 )
{
void T_4 * V_28 [ 2 ] ;
int V_29 , V_13 ;
unsigned int V_30 ;
struct V_31 * V_31 ;
V_31 = F_18 ( V_27 , 0 ) ;
if ( F_19 ( V_31 ) ) {
F_20 ( L_1 ) ;
return;
}
V_28 [ V_32 ] = F_21 ( V_27 , 0 ) ;
if ( ! V_28 [ V_32 ] ) {
F_20 ( L_2 ) ;
goto V_33;
}
V_28 [ V_34 ] = F_21 ( V_27 , 1 ) ;
if ( ! V_28 [ V_34 ] ) {
F_20 ( L_2 ) ;
goto V_35;
}
V_13 = F_22 ( V_27 , 0 ) ;
if ( ! V_13 ) {
F_20 ( L_3 ) ;
goto V_36;
}
F_23 ( V_27 , L_4 , & V_30 ) ;
V_1 . V_11 = V_28 [ V_32 ] ;
V_1 . V_8 = V_28 [ V_34 ] ;
V_1 . V_24 = V_30 ;
V_1 . V_10 = V_30 ;
V_1 . V_23 = 4 + V_30 ;
V_29 = F_24 ( V_13 , F_6 ,
V_37 , V_1 . V_18 . V_38 , & V_1 ) ;
if ( V_29 < 0 ) {
F_20 ( L_5 , V_13 ) ;
goto V_36;
}
F_25 ( & V_1 . V_18 ,
F_26 ( V_31 ) / 8 ) ;
return;
V_36:
F_27 ( V_28 [ V_34 ] ) ;
V_35:
F_27 ( V_28 [ V_32 ] ) ;
V_33:
F_28 ( V_31 ) ;
}
