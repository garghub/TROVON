static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
if ( ! F_2 ( V_2 ) )
return - V_5 ;
V_3 = F_3 ( V_2 , V_6 ) ;
if ( ! V_3 )
return - V_5 ;
F_4 ( V_2 , V_3 + V_7 , & V_4 ) ;
if ( V_4 & V_8 )
V_4 |= V_9 ;
if ( V_4 & V_10 )
V_4 |= V_11 ;
F_5 ( V_2 , V_3 + V_7 , V_4 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
if ( ! F_2 ( V_2 ) )
return - V_5 ;
V_3 = F_3 ( V_2 , V_6 ) ;
if ( ! V_3 )
return - V_5 ;
F_4 ( V_2 , V_3 + V_7 , & V_4 ) ;
V_4 &= ~ ( V_9 | V_11 ) ;
F_5 ( V_2 , V_3 + V_7 , V_4 ) ;
return 0 ;
}
void F_7 ( struct V_1 * V_2 )
{
switch ( V_12 ) {
case V_13 :
return;
case V_14 :
F_6 ( V_2 ) ;
break;
case V_15 :
F_1 ( V_2 ) ;
break;
default:
return;
}
}
void F_8 ( char * V_16 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < F_9 ( V_18 ) ; V_17 ++ )
if ( ! strncmp ( V_16 , V_18 [ V_17 ] ,
strlen ( V_18 [ V_17 ] ) ) )
break;
if ( V_17 >= F_9 ( V_18 ) )
return;
V_12 = V_17 ;
}
