static void F_1 ( int V_1 )
{
if ( V_2 [ V_1 ] -> V_3 != NULL )
while ( ! F_2 ( V_4 ) && V_2 [ V_1 ] -> V_3 ( V_1 ) )
F_3 ( & V_5 [ V_1 ] ,
V_6 / 10 ) ;
}
static void F_4 ( int V_1 , unsigned char V_7 )
{
if ( V_8 [ V_1 ] == NULL )
return;
if ( V_7 == 0xfe )
return;
if ( F_5 ( V_8 [ V_1 ] ) ) {
F_6 ( V_8 [ V_1 ] , V_7 ) ;
F_7 ( & V_9 [ V_1 ] ) ;
}
}
static void F_8 ( int V_1 )
{
}
static void F_9 ( unsigned long V_10 )
{
unsigned long V_11 ;
int V_1 ;
F_10 ( & V_12 , V_11 ) ;
if ( V_13 )
{
for ( V_1 = 0 ; V_1 < V_14 ; V_1 ++ )
if ( V_2 [ V_1 ] != NULL && V_15 [ V_1 ] != NULL )
{
while ( F_11 ( V_15 [ V_1 ] ) )
{
int V_16 ;
int V_17 = V_15 [ V_1 ] -> V_18 [ V_15 [ V_1 ] -> V_19 ] ;
F_12 ( & V_12 , V_11 ) ;
V_16 = V_2 [ V_1 ] -> F_13 ( V_1 , V_17 ) ;
F_10 ( & V_12 , V_11 ) ;
if ( ! V_16 )
break;
V_15 [ V_1 ] -> V_19 = ( V_15 [ V_1 ] -> V_19 + 1 ) % V_20 ;
V_15 [ V_1 ] -> V_21 -- ;
}
if ( F_11 ( V_15 [ V_1 ] ) < 100 )
F_7 ( & V_5 [ V_1 ] ) ;
}
V_22 . V_23 = ( 1 ) + V_24 ;
F_14 ( & V_22 ) ;
}
F_12 ( & V_12 , V_11 ) ;
}
int F_15 ( int V_1 , struct V_25 * V_25 )
{
int V_26 , V_27 ;
V_1 = V_1 >> 4 ;
V_26 = F_16 ( V_25 ) ;
if ( V_14 > V_28 )
{
F_17 ( V_29 L_1 ) ;
V_14 = V_28 ;
}
if ( V_1 < 0 || V_1 >= V_14 || V_2 [ V_1 ] == NULL )
return - V_30 ;
F_18 ( V_2 [ V_1 ] -> V_31 ) ;
if ( ( V_27 = V_2 [ V_1 ] -> F_19 ( V_1 , V_26 ,
F_4 , F_8 ) ) < 0 )
return V_27 ;
V_32 [ V_1 ] . V_33 = V_34 ;
V_8 [ V_1 ] = F_20 ( sizeof( struct V_35 ) ) ;
if ( V_8 [ V_1 ] == NULL )
{
F_17 ( V_36 L_2 ) ;
V_2 [ V_1 ] -> F_21 ( V_1 ) ;
return - V_37 ;
}
V_8 [ V_1 ] -> V_21 = V_8 [ V_1 ] -> V_19 = V_8 [ V_1 ] -> V_38 = 0 ;
V_15 [ V_1 ] = F_20 ( sizeof( struct V_35 ) ) ;
if ( V_15 [ V_1 ] == NULL )
{
F_17 ( V_36 L_2 ) ;
V_2 [ V_1 ] -> F_21 ( V_1 ) ;
F_22 ( V_8 [ V_1 ] ) ;
V_8 [ V_1 ] = NULL ;
return - V_37 ;
}
V_15 [ V_1 ] -> V_21 = V_15 [ V_1 ] -> V_19 = V_15 [ V_1 ] -> V_38 = 0 ;
V_13 ++ ;
F_23 ( & V_5 [ V_1 ] ) ;
F_23 ( & V_9 [ V_1 ] ) ;
if ( V_13 < 2 )
{
V_22 . V_23 = 1 + V_24 ;
F_14 ( & V_22 ) ;
}
return V_27 ;
}
void F_24 ( int V_1 , struct V_25 * V_25 )
{
int V_26 ;
V_1 = V_1 >> 4 ;
V_26 = F_16 ( V_25 ) ;
if ( V_1 < 0 || V_1 >= V_14 || V_2 [ V_1 ] == NULL )
return;
if ( V_26 != V_39 )
{
V_2 [ V_1 ] -> F_13 ( V_1 , 0xfe ) ;
while ( ! F_2 ( V_4 ) && F_11 ( V_15 [ V_1 ] ) )
F_25 ( & V_5 [ V_1 ] ) ;
F_1 ( V_1 ) ;
}
V_2 [ V_1 ] -> F_21 ( V_1 ) ;
V_13 -- ;
if ( V_13 == 0 )
F_26 ( & V_22 ) ;
F_22 ( V_8 [ V_1 ] ) ;
F_22 ( V_15 [ V_1 ] ) ;
V_8 [ V_1 ] = NULL ;
V_15 [ V_1 ] = NULL ;
F_18 ( V_2 [ V_1 ] -> V_31 ) ;
}
int F_27 ( int V_1 , struct V_25 * V_25 , const char T_1 * V_40 , int V_41 )
{
int V_17 , V_42 , V_43 ;
unsigned char V_44 ;
V_1 = V_1 >> 4 ;
if ( ! V_41 )
return 0 ;
V_17 = 0 ;
while ( V_17 < V_41 )
{
V_42 = F_5 ( V_15 [ V_1 ] ) ;
if ( V_42 == 0 ) {
if ( V_25 -> V_45 & V_46 ) {
V_17 = - V_47 ;
goto V_48;
}
F_25 ( & V_5 [ V_1 ] ) ;
if ( F_2 ( V_4 ) )
{
V_17 = - V_49 ;
goto V_48;
}
V_42 = F_5 ( V_15 [ V_1 ] ) ;
}
if ( V_42 > ( V_41 - V_17 ) )
V_42 = V_41 - V_17 ;
for ( V_43 = 0 ; V_43 < V_42 ; V_43 ++ )
{
if ( F_28 ( ( char * ) & V_44 , & ( V_40 ) [ V_17 ] , 1 ) ) {
V_17 = - V_50 ;
goto V_48;
}
F_6 ( V_15 [ V_1 ] , V_44 ) ;
V_17 ++ ;
}
}
V_48:
return V_17 ;
}
int F_29 ( int V_1 , struct V_25 * V_25 , char T_1 * V_40 , int V_41 )
{
int V_42 , V_17 = 0 ;
unsigned char V_44 ;
V_1 = V_1 >> 4 ;
if ( ! F_11 ( V_8 [ V_1 ] ) ) {
if ( V_25 -> V_45 & V_46 ) {
V_17 = - V_47 ;
goto V_48;
}
F_3 ( & V_9 [ V_1 ] ,
V_32 [ V_1 ] . V_33 ) ;
if ( F_2 ( V_4 ) )
V_17 = - V_49 ;
}
if ( V_17 == 0 && F_11 ( V_8 [ V_1 ] ) )
{
V_42 = F_11 ( V_8 [ V_1 ] ) ;
if ( V_42 > V_41 )
V_42 = V_41 ;
V_17 = 0 ;
while ( V_17 < V_42 )
{
char * V_51 ;
F_30 ( V_8 [ V_1 ] , V_44 ) ;
V_51 = ( char * ) & V_44 ;
if ( F_31 ( & ( V_40 ) [ V_17 ] , V_51 , 1 ) ) {
V_17 = - V_50 ;
goto V_48;
}
V_17 ++ ;
}
}
V_48:
return V_17 ;
}
int F_32 ( int V_1 , struct V_25 * V_25 ,
unsigned int V_52 , void T_1 * V_53 )
{
int V_54 ;
V_1 = V_1 >> 4 ;
if ( ( ( V_52 >> 8 ) & 0xff ) == 'C' )
{
if ( V_2 [ V_1 ] -> V_55 )
return V_2 [ V_1 ] -> V_55 -> V_56 ( V_2 [ V_1 ] -> V_55 -> V_57 , V_52 , V_53 , 0 ) ;
return - V_30 ;
}
else
{
switch ( V_52 )
{
case V_58 :
if ( F_33 ( V_54 , ( int T_1 * ) V_53 ) )
return - V_50 ;
if ( V_54 < 0 )
V_54 = 0 ;
V_54 = ( V_6 * V_54 ) / 10 ;
V_32 [ V_1 ] . V_33 = V_54 ;
return F_34 ( V_54 , ( int T_1 * ) V_53 ) ;
default:
if ( ! V_2 [ V_1 ] -> V_56 )
return - V_59 ;
return V_2 [ V_1 ] -> V_56 ( V_1 , V_52 , V_53 ) ;
}
}
}
unsigned int F_35 ( int V_1 , struct V_25 * V_25 , T_2 * V_60 )
{
unsigned int V_61 = 0 ;
V_1 = V_1 >> 4 ;
F_36 ( V_25 , & V_9 [ V_1 ] , V_60 ) ;
if ( F_11 ( V_8 [ V_1 ] ) )
V_61 |= V_62 | V_63 ;
F_36 ( V_25 , & V_5 [ V_1 ] , V_60 ) ;
if ( ! F_5 ( V_15 [ V_1 ] ) )
V_61 |= V_64 | V_65 ;
return V_61 ;
}
int F_37 ( int V_1 )
{
if ( V_8 [ V_1 ] )
return F_11 ( V_8 [ V_1 ] ) ;
return 0 ;
}
