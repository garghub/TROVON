void F_1 ( unsigned long * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
int V_6 ;
V_1 [ V_7 ] = 0 ;
for ( V_6 = 0 ; V_6 < 15 ; V_6 ++ )
V_1 [ V_8 + V_6 ] = V_3 -> V_9 [ V_10 + V_6 ] ;
V_5 = (struct V_4 * ) V_3 -> V_9 [ V_11 ] ;
for ( V_6 = 0 ; V_6 < 8 ; V_6 ++ )
V_1 [ V_12 + V_6 ] = V_5 -> V_13 [ V_6 ] ;
for ( V_6 = 0 ; V_6 < 8 ; V_6 ++ )
V_1 [ V_14 + V_6 ] = V_5 -> V_15 [ V_6 ] ;
for ( V_6 = V_16 ; V_6 <= V_17 ; V_6 ++ )
V_1 [ V_6 ] = 0 ;
V_1 [ V_18 ] = V_3 -> V_19 ;
V_1 [ V_20 ] = V_3 -> V_21 ;
V_1 [ V_22 ] = 0 ;
V_1 [ V_23 ] = ( unsigned long ) & V_24 ;
V_1 [ V_25 ] = V_3 -> V_26 ;
V_1 [ V_27 ] = V_3 -> V_28 ;
V_1 [ V_29 ] = 0 ;
V_1 [ V_30 ] = 0 ;
}
void F_2 ( unsigned long * V_1 , struct V_31 * V_32 )
{
struct V_33 * V_34 = F_3 ( V_32 ) ;
struct V_4 * V_5 ;
int V_6 ;
for ( V_6 = V_7 ; V_6 < V_35 ; V_6 ++ )
V_1 [ V_6 ] = 0 ;
V_1 [ V_35 ] = ( unsigned long ) V_34 ;
V_1 [ V_36 ] = 0 ;
for ( V_6 = V_37 ; V_6 < V_38 ; V_6 ++ )
V_1 [ V_6 ] = 0 ;
V_1 [ V_38 ] = V_34 -> V_39 ;
V_1 [ V_40 ] = 0 ;
V_5 = (struct V_4 * ) V_34 -> V_39 ;
for ( V_6 = 0 ; V_6 < 8 ; V_6 ++ )
V_1 [ V_12 + V_6 ] = V_5 -> V_13 [ V_6 ] ;
for ( V_6 = 0 ; V_6 < 8 ; V_6 ++ )
V_1 [ V_14 + V_6 ] = V_5 -> V_15 [ V_6 ] ;
for ( V_6 = V_16 ; V_6 <= V_17 ; V_6 ++ )
V_1 [ V_6 ] = 0 ;
V_1 [ V_18 ] = 0 ;
V_1 [ V_20 ] = V_34 -> V_41 ;
V_1 [ V_22 ] = V_34 -> V_42 ;
V_1 [ V_23 ] = ( unsigned long ) & V_24 ;
V_1 [ V_25 ] = V_34 -> V_43 ;
V_1 [ V_27 ] = V_34 -> V_43 + 4 ;
V_1 [ V_29 ] = 0 ;
V_1 [ V_30 ] = 0 ;
}
void F_4 ( unsigned long * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < 15 ; V_6 ++ )
V_3 -> V_9 [ V_10 + V_6 ] = V_1 [ V_8 + V_6 ] ;
if ( V_3 -> V_21 != V_1 [ V_20 ] ) {
unsigned long V_44 = V_3 -> V_21 & V_45 ;
V_3 -> V_21 = ( V_1 [ V_20 ] & ~ V_45 ) | V_44 ;
}
V_3 -> V_26 = V_1 [ V_25 ] ;
V_3 -> V_28 = V_1 [ V_27 ] ;
V_3 -> V_19 = V_1 [ V_18 ] ;
V_5 = (struct V_4 * ) V_3 -> V_9 [ V_11 ] ;
for ( V_6 = 0 ; V_6 < 8 ; V_6 ++ )
V_5 -> V_13 [ V_6 ] = V_1 [ V_12 + V_6 ] ;
for ( V_6 = 0 ; V_6 < 8 ; V_6 ++ )
V_5 -> V_15 [ V_6 ] = V_1 [ V_14 + V_6 ] ;
}
int F_5 ( int V_46 , int V_47 , int V_48 ,
char * V_49 , char * V_50 ,
struct V_2 * V_51 )
{
unsigned long V_52 ;
char * V_53 ;
switch ( V_49 [ 0 ] ) {
case 'c' :
V_53 = & V_49 [ 1 ] ;
if ( F_6 ( & V_53 , & V_52 ) ) {
V_51 -> V_26 = V_52 ;
V_51 -> V_28 = V_52 + 4 ;
}
case 'D' :
case 'k' :
if ( V_51 -> V_26 == ( unsigned long ) V_54 ) {
V_51 -> V_26 = V_51 -> V_28 ;
V_51 -> V_28 += 4 ;
}
return 0 ;
}
return - 1 ;
}
T_1 void F_7 ( unsigned long V_55 , struct V_2 * V_3 )
{
unsigned long V_56 ;
if ( F_8 ( V_3 ) ) {
F_9 ( V_3 , V_55 ) ;
return;
}
F_10 () ;
F_11 ( V_56 ) ;
F_12 ( V_55 , V_57 , 0 , V_3 ) ;
F_13 ( V_56 ) ;
}
int F_14 ( void )
{
return 0 ;
}
void F_15 ( void )
{
}
void F_16 ( struct V_2 * V_3 , unsigned long V_58 )
{
V_3 -> V_26 = V_58 ;
V_3 -> V_28 = V_3 -> V_26 + 4 ;
}
