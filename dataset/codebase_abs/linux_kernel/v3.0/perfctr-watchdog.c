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
case 15 :
return V_1 - V_12 ;
}
}
return 0 ;
}
static inline unsigned int F_3 ( unsigned int V_1 )
{
switch ( V_2 . V_3 ) {
case V_4 :
if ( V_1 >= V_13 )
return ( V_1 - V_13 ) >> 1 ;
return V_1 - V_14 ;
case V_7 :
if ( F_2 ( & V_2 , V_8 ) )
return V_1 - V_15 ;
switch ( V_2 . V_10 ) {
case 6 :
return V_1 - V_16 ;
case 15 :
return V_1 - V_17 ;
}
}
return 0 ;
}
int F_4 ( unsigned int V_18 )
{
F_5 ( V_18 > V_19 ) ;
return ! F_6 ( V_18 , V_20 ) ;
}
int F_7 ( unsigned int V_1 )
{
unsigned int V_18 ;
V_18 = F_1 ( V_1 ) ;
if ( V_18 > V_19 )
return 1 ;
if ( ! F_8 ( V_18 , V_20 ) )
return 1 ;
return 0 ;
}
void F_9 ( unsigned int V_1 )
{
unsigned int V_18 ;
V_18 = F_1 ( V_1 ) ;
if ( V_18 > V_19 )
return;
F_10 ( V_18 , V_20 ) ;
}
int F_11 ( unsigned int V_1 )
{
unsigned int V_18 ;
V_18 = F_3 ( V_1 ) ;
if ( V_18 > V_19 )
return 1 ;
if ( ! F_8 ( V_18 , V_21 ) )
return 1 ;
return 0 ;
}
void F_12 ( unsigned int V_1 )
{
unsigned int V_18 ;
V_18 = F_3 ( V_1 ) ;
if ( V_18 > V_19 )
return;
F_10 ( V_18 , V_21 ) ;
}
