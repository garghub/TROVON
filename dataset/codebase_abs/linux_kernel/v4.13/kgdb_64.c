void F_1 ( unsigned long * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
int V_6 ;
V_1 [ V_7 ] = 0 ;
for ( V_6 = 0 ; V_6 < 15 ; V_6 ++ )
V_1 [ V_8 + V_6 ] = V_3 -> V_9 [ V_10 + V_6 ] ;
V_5 = (struct V_4 * ) ( V_3 -> V_9 [ V_11 ] + V_12 ) ;
for ( V_6 = 0 ; V_6 < 8 ; V_6 ++ )
V_1 [ V_13 + V_6 ] = V_5 -> V_14 [ V_6 ] ;
for ( V_6 = 0 ; V_6 < 8 ; V_6 ++ )
V_1 [ V_15 + V_6 ] = V_5 -> V_16 [ V_6 ] ;
for ( V_6 = V_17 ; V_6 <= V_18 ; V_6 ++ )
V_1 [ V_6 ] = 0 ;
V_1 [ V_19 ] = V_3 -> V_20 ;
V_1 [ V_21 ] = V_3 -> V_22 ;
V_1 [ V_23 ] = V_3 -> V_24 ;
V_1 [ V_25 ] = 0 ;
V_1 [ V_26 ] = 0 ;
V_1 [ V_27 ] = V_3 -> V_28 ;
}
void F_2 ( unsigned long * V_1 , struct V_29 * V_30 )
{
struct V_31 * V_32 = F_3 ( V_30 ) ;
extern unsigned int V_33 ;
extern unsigned int V_34 ;
struct V_4 * V_5 ;
unsigned long V_35 , V_36 ;
int V_6 ;
for ( V_6 = V_7 ; V_6 < V_37 ; V_6 ++ )
V_1 [ V_6 ] = 0 ;
V_1 [ V_37 ] = ( unsigned long ) V_32 ;
V_1 [ V_38 ] = ( unsigned long ) V_30 ;
for ( V_6 = V_39 ; V_6 < V_40 ; V_6 ++ )
V_1 [ V_6 ] = 0 ;
V_1 [ V_40 ] = V_32 -> V_41 ;
V_1 [ V_42 ] = 0 ;
V_5 = (struct V_4 * ) ( V_32 -> V_41 + V_12 ) ;
for ( V_6 = 0 ; V_6 < 8 ; V_6 ++ )
V_1 [ V_13 + V_6 ] = V_5 -> V_14 [ V_6 ] ;
for ( V_6 = 0 ; V_6 < 8 ; V_6 ++ )
V_1 [ V_15 + V_6 ] = V_5 -> V_16 [ V_6 ] ;
for ( V_6 = V_17 ; V_6 <= V_18 ; V_6 ++ )
V_1 [ V_6 ] = 0 ;
if ( V_32 -> V_43 )
V_35 = ( unsigned long ) & V_34 ;
else
V_35 = ( unsigned long ) & V_33 ;
V_1 [ V_19 ] = V_35 ;
V_1 [ V_21 ] = V_35 + 4 ;
V_36 = F_4 ( V_32 ) [ V_44 ] ;
V_1 [ V_23 ] = ( V_45 | V_46 | V_36 ) ;
V_1 [ V_25 ] = 0 ;
V_1 [ V_26 ] = 0 ;
V_1 [ V_27 ] = 0 ;
}
void F_5 ( unsigned long * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < 15 ; V_6 ++ )
V_3 -> V_9 [ V_10 + V_6 ] = V_1 [ V_8 + V_6 ] ;
if ( V_3 -> V_24 != V_1 [ V_23 ] ) {
unsigned long V_36 = V_3 -> V_24 & V_47 ;
V_3 -> V_24 = ( V_1 [ V_23 ] & ~ V_47 ) | V_36 ;
}
V_3 -> V_20 = V_1 [ V_19 ] ;
V_3 -> V_22 = V_1 [ V_21 ] ;
V_3 -> V_28 = V_1 [ V_27 ] ;
V_5 = (struct V_4 * ) ( V_3 -> V_9 [ V_11 ] + V_12 ) ;
for ( V_6 = 0 ; V_6 < 8 ; V_6 ++ )
V_5 -> V_14 [ V_6 ] = V_1 [ V_13 + V_6 ] ;
for ( V_6 = 0 ; V_6 < 8 ; V_6 ++ )
V_5 -> V_16 [ V_6 ] = V_1 [ V_15 + V_6 ] ;
}
void T_1 F_6 ( int V_48 , struct V_2 * V_3 )
{
unsigned long V_49 ;
__asm__ __volatile__("rdpr %%pstate, %0\n\t"
"wrpr %0, %1, %%pstate"
: "=r" (flags)
: "i" (PSTATE_IE));
F_7 () ;
if ( F_8 ( & V_50 ) != - 1 )
F_9 ( F_10 () , V_3 ) ;
__asm__ __volatile__("wrpr %0, 0, %%pstate"
: : "r" (flags));
}
int F_11 ( int V_51 , int V_52 , int V_53 ,
char * V_54 , char * V_55 ,
struct V_2 * V_56 )
{
unsigned long V_57 ;
char * V_58 ;
switch ( V_54 [ 0 ] ) {
case 'c' :
V_58 = & V_54 [ 1 ] ;
if ( F_12 ( & V_58 , & V_57 ) ) {
V_56 -> V_20 = V_57 ;
V_56 -> V_22 = V_57 + 4 ;
}
case 'D' :
case 'k' :
if ( V_56 -> V_20 == ( unsigned long ) V_59 ) {
V_56 -> V_20 = V_56 -> V_22 ;
V_56 -> V_22 += 4 ;
}
return 0 ;
}
return - 1 ;
}
T_2 void F_13 ( unsigned long V_60 , struct V_2 * V_3 )
{
enum V_61 V_62 = F_14 () ;
unsigned long V_49 ;
if ( F_15 ( V_3 ) ) {
F_16 ( V_3 , V_60 ) ;
goto V_63;
}
F_7 () ;
F_17 ( V_49 ) ;
F_18 ( 0x172 , V_64 , 0 , V_3 ) ;
F_19 ( V_49 ) ;
V_63:
F_20 ( V_62 ) ;
}
int F_21 ( void )
{
return 0 ;
}
void F_22 ( void )
{
}
void F_23 ( struct V_2 * V_3 , unsigned long V_65 )
{
V_3 -> V_20 = V_65 ;
V_3 -> V_22 = V_3 -> V_20 + 4 ;
}
