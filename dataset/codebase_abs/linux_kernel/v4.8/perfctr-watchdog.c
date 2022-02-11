static inline unsigned int F_1 ( unsigned int V_1 )
{
switch ( V_2 . V_3 ) {
case V_4 :
if ( V_1 >= V_5 )
return ( V_1 - V_5 ) >> 1 ;
return V_1 - V_6 ;
case V_7 :
if ( F_2 ( & V_2 , V_8 ) )
return V_1 - V_9 ;
switch ( V_2 . V_10 ) {
case 6 :
return V_1 - V_11 ;
case 11 :
return V_1 - V_12 ;
case 15 :
return V_1 - V_13 ;
}
}
return 0 ;
}
static inline unsigned int F_3 ( unsigned int V_1 )
{
switch ( V_2 . V_3 ) {
case V_4 :
if ( V_1 >= V_14 )
return ( V_1 - V_14 ) >> 1 ;
return V_1 - V_15 ;
case V_7 :
if ( F_2 ( & V_2 , V_8 ) )
return V_1 - V_16 ;
switch ( V_2 . V_10 ) {
case 6 :
return V_1 - V_17 ;
case 11 :
return V_1 - V_18 ;
case 15 :
return V_1 - V_19 ;
}
}
return 0 ;
}
int F_4 ( unsigned int V_20 )
{
F_5 ( V_20 > V_21 ) ;
return ! F_6 ( V_20 , V_22 ) ;
}
int F_7 ( unsigned int V_1 )
{
unsigned int V_20 ;
V_20 = F_1 ( V_1 ) ;
if ( V_20 > V_21 )
return 1 ;
if ( ! F_8 ( V_20 , V_22 ) )
return 1 ;
return 0 ;
}
void F_9 ( unsigned int V_1 )
{
unsigned int V_20 ;
V_20 = F_1 ( V_1 ) ;
if ( V_20 > V_21 )
return;
F_10 ( V_20 , V_22 ) ;
}
int F_11 ( unsigned int V_1 )
{
unsigned int V_20 ;
V_20 = F_3 ( V_1 ) ;
if ( V_20 > V_21 )
return 1 ;
if ( ! F_8 ( V_20 , V_23 ) )
return 1 ;
return 0 ;
}
void F_12 ( unsigned int V_1 )
{
unsigned int V_20 ;
V_20 = F_3 ( V_1 ) ;
if ( V_20 > V_21 )
return;
F_10 ( V_20 , V_23 ) ;
}
