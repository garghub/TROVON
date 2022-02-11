static void F_1 ( int V_1 )
{
if ( V_2 [ V_1 ] -> V_3 != NULL )
F_2 ( V_4 [ V_1 ] ,
! V_2 [ V_1 ] -> V_3 ( V_1 ) , V_5 / 10 ) ;
}
static void F_3 ( int V_1 , unsigned char V_6 )
{
if ( V_7 [ V_1 ] == NULL )
return;
if ( V_6 == 0xfe )
return;
if ( F_4 ( V_7 [ V_1 ] ) ) {
F_5 ( V_7 [ V_1 ] , V_6 ) ;
F_6 ( & V_8 [ V_1 ] ) ;
}
}
static void F_7 ( int V_1 )
{
}
static void F_8 ( unsigned long V_9 )
{
unsigned long V_10 ;
int V_1 ;
F_9 ( & V_11 , V_10 ) ;
if ( V_12 )
{
for ( V_1 = 0 ; V_1 < V_13 ; V_1 ++ )
if ( V_2 [ V_1 ] != NULL && V_14 [ V_1 ] != NULL )
{
while ( F_10 ( V_14 [ V_1 ] ) )
{
int V_15 ;
int V_16 = V_14 [ V_1 ] -> V_17 [ V_14 [ V_1 ] -> V_18 ] ;
F_11 ( & V_11 , V_10 ) ;
V_15 = V_2 [ V_1 ] -> F_12 ( V_1 , V_16 ) ;
F_9 ( & V_11 , V_10 ) ;
if ( ! V_15 )
break;
V_14 [ V_1 ] -> V_18 = ( V_14 [ V_1 ] -> V_18 + 1 ) % V_19 ;
V_14 [ V_1 ] -> V_20 -- ;
}
if ( F_10 ( V_14 [ V_1 ] ) < 100 )
F_6 ( & V_4 [ V_1 ] ) ;
}
V_21 . V_22 = ( 1 ) + V_23 ;
F_13 ( & V_21 ) ;
}
F_11 ( & V_11 , V_10 ) ;
}
int F_14 ( int V_1 , struct V_24 * V_24 )
{
int V_25 , V_26 ;
V_1 = V_1 >> 4 ;
V_25 = F_15 ( V_24 ) ;
if ( V_13 > V_27 )
{
F_16 ( V_28 L_1 ) ;
V_13 = V_27 ;
}
if ( V_1 < 0 || V_1 >= V_13 || V_2 [ V_1 ] == NULL )
return - V_29 ;
F_17 ( V_2 [ V_1 ] -> V_30 ) ;
if ( ( V_26 = V_2 [ V_1 ] -> F_18 ( V_1 , V_25 ,
F_3 , F_7 ) ) < 0 )
return V_26 ;
V_31 [ V_1 ] . V_32 = V_33 ;
V_7 [ V_1 ] = F_19 ( sizeof( struct V_34 ) ) ;
if ( V_7 [ V_1 ] == NULL )
{
F_16 ( V_35 L_2 ) ;
V_2 [ V_1 ] -> F_20 ( V_1 ) ;
return - V_36 ;
}
V_7 [ V_1 ] -> V_20 = V_7 [ V_1 ] -> V_18 = V_7 [ V_1 ] -> V_37 = 0 ;
V_14 [ V_1 ] = F_19 ( sizeof( struct V_34 ) ) ;
if ( V_14 [ V_1 ] == NULL )
{
F_16 ( V_35 L_2 ) ;
V_2 [ V_1 ] -> F_20 ( V_1 ) ;
F_21 ( V_7 [ V_1 ] ) ;
V_7 [ V_1 ] = NULL ;
return - V_36 ;
}
V_14 [ V_1 ] -> V_20 = V_14 [ V_1 ] -> V_18 = V_14 [ V_1 ] -> V_37 = 0 ;
V_12 ++ ;
F_22 ( & V_4 [ V_1 ] ) ;
F_22 ( & V_8 [ V_1 ] ) ;
if ( V_12 < 2 )
{
V_21 . V_22 = 1 + V_23 ;
F_13 ( & V_21 ) ;
}
return V_26 ;
}
void F_23 ( int V_1 , struct V_24 * V_24 )
{
int V_25 ;
V_1 = V_1 >> 4 ;
V_25 = F_15 ( V_24 ) ;
if ( V_1 < 0 || V_1 >= V_13 || V_2 [ V_1 ] == NULL )
return;
if ( V_25 != V_38 )
{
V_2 [ V_1 ] -> F_12 ( V_1 , 0xfe ) ;
F_24 ( V_4 [ V_1 ] ,
! F_10 ( V_14 [ V_1 ] ) ) ;
F_1 ( V_1 ) ;
}
V_2 [ V_1 ] -> F_20 ( V_1 ) ;
V_12 -- ;
if ( V_12 == 0 )
F_25 ( & V_21 ) ;
F_21 ( V_7 [ V_1 ] ) ;
F_21 ( V_14 [ V_1 ] ) ;
V_7 [ V_1 ] = NULL ;
V_14 [ V_1 ] = NULL ;
F_17 ( V_2 [ V_1 ] -> V_30 ) ;
}
int F_26 ( int V_1 , struct V_24 * V_24 , const char T_1 * V_39 , int V_40 )
{
int V_16 , V_41 , V_42 ;
unsigned char V_43 ;
V_1 = V_1 >> 4 ;
if ( ! V_40 )
return 0 ;
V_16 = 0 ;
while ( V_16 < V_40 )
{
V_41 = F_4 ( V_14 [ V_1 ] ) ;
if ( V_41 == 0 ) {
if ( V_24 -> V_44 & V_45 ) {
V_16 = - V_46 ;
goto V_47;
}
if ( F_24 ( V_4 [ V_1 ] ,
F_4 ( V_14 [ V_1 ] ) ) )
{
V_16 = - V_48 ;
goto V_47;
}
V_41 = F_4 ( V_14 [ V_1 ] ) ;
}
if ( V_41 > ( V_40 - V_16 ) )
V_41 = V_40 - V_16 ;
for ( V_42 = 0 ; V_42 < V_41 ; V_42 ++ )
{
if ( F_27 ( ( char * ) & V_43 , & ( V_39 ) [ V_16 ] , 1 ) ) {
V_16 = - V_49 ;
goto V_47;
}
F_5 ( V_14 [ V_1 ] , V_43 ) ;
V_16 ++ ;
}
}
V_47:
return V_16 ;
}
int F_28 ( int V_1 , struct V_24 * V_24 , char T_1 * V_39 , int V_40 )
{
int V_41 , V_16 = 0 ;
unsigned char V_43 ;
V_1 = V_1 >> 4 ;
if ( ! F_10 ( V_7 [ V_1 ] ) ) {
if ( V_24 -> V_44 & V_45 ) {
V_16 = - V_46 ;
goto V_47;
}
F_2 ( V_8 [ V_1 ] ,
F_10 ( V_7 [ V_1 ] ) ,
V_31 [ V_1 ] . V_32 ) ;
if ( F_29 ( V_50 ) )
V_16 = - V_48 ;
}
if ( V_16 == 0 && F_10 ( V_7 [ V_1 ] ) )
{
V_41 = F_10 ( V_7 [ V_1 ] ) ;
if ( V_41 > V_40 )
V_41 = V_40 ;
V_16 = 0 ;
while ( V_16 < V_41 )
{
char * V_51 ;
F_30 ( V_7 [ V_1 ] , V_43 ) ;
V_51 = ( char * ) & V_43 ;
if ( F_31 ( & ( V_39 ) [ V_16 ] , V_51 , 1 ) ) {
V_16 = - V_49 ;
goto V_47;
}
V_16 ++ ;
}
}
V_47:
return V_16 ;
}
int F_32 ( int V_1 , struct V_24 * V_24 ,
unsigned int V_52 , void T_1 * V_53 )
{
int V_54 ;
V_1 = V_1 >> 4 ;
if ( ( ( V_52 >> 8 ) & 0xff ) == 'C' )
{
if ( V_2 [ V_1 ] -> V_55 )
return V_2 [ V_1 ] -> V_55 -> V_56 ( V_2 [ V_1 ] -> V_55 -> V_57 , V_52 , V_53 , 0 ) ;
return - V_29 ;
}
else
{
switch ( V_52 )
{
case V_58 :
if ( F_33 ( V_54 , ( int T_1 * ) V_53 ) )
return - V_49 ;
if ( V_54 < 0 )
V_54 = 0 ;
V_54 = ( V_5 * V_54 ) / 10 ;
V_31 [ V_1 ] . V_32 = V_54 ;
return F_34 ( V_54 , ( int T_1 * ) V_53 ) ;
default:
if ( ! V_2 [ V_1 ] -> V_56 )
return - V_59 ;
return V_2 [ V_1 ] -> V_56 ( V_1 , V_52 , V_53 ) ;
}
}
}
unsigned int F_35 ( int V_1 , struct V_24 * V_24 , T_2 * V_60 )
{
unsigned int V_61 = 0 ;
V_1 = V_1 >> 4 ;
F_36 ( V_24 , & V_8 [ V_1 ] , V_60 ) ;
if ( F_10 ( V_7 [ V_1 ] ) )
V_61 |= V_62 | V_63 ;
F_36 ( V_24 , & V_4 [ V_1 ] , V_60 ) ;
if ( ! F_4 ( V_14 [ V_1 ] ) )
V_61 |= V_64 | V_65 ;
return V_61 ;
}
int F_37 ( int V_1 )
{
if ( V_7 [ V_1 ] )
return F_10 ( V_7 [ V_1 ] ) ;
return 0 ;
}
