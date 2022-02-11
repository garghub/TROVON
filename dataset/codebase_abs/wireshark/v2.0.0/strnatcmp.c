static int
F_1 ( T_1 V_1 )
{
return F_2 ( V_1 ) ;
}
static int
F_3 ( T_1 V_1 )
{
return F_4 ( V_1 ) ;
}
static T_1
F_5 ( T_1 V_1 )
{
return F_6 ( V_1 ) ;
}
static int
F_7 ( T_1 const * V_1 , T_1 const * V_2 )
{
int V_3 = 0 ;
for (; ; V_1 ++ , V_2 ++ ) {
if ( ! F_1 ( * V_1 ) && ! F_1 ( * V_2 ) )
return V_3 ;
else if ( ! F_1 ( * V_1 ) )
return - 1 ;
else if ( ! F_1 ( * V_2 ) )
return + 1 ;
else if ( * V_1 < * V_2 ) {
if ( ! V_3 )
V_3 = - 1 ;
} else if ( * V_1 > * V_2 ) {
if ( ! V_3 )
V_3 = + 1 ;
} else if ( ! * V_1 && ! * V_2 )
return V_3 ;
}
return 0 ;
}
static int
F_8 ( T_1 const * V_1 , T_1 const * V_2 )
{
for (; ; V_1 ++ , V_2 ++ ) {
if ( ! F_1 ( * V_1 ) && ! F_1 ( * V_2 ) )
return 0 ;
else if ( ! F_1 ( * V_1 ) )
return - 1 ;
else if ( ! F_1 ( * V_2 ) )
return + 1 ;
else if ( * V_1 < * V_2 )
return - 1 ;
else if ( * V_1 > * V_2 )
return + 1 ;
}
return 0 ;
}
static int F_9 ( T_1 const * V_1 , T_1 const * V_2 , int V_4 )
{
int V_5 , V_6 ;
T_1 V_7 , V_8 ;
int V_9 , V_10 ;
if ( ! V_1 || ! V_2 ) {
if ( ! V_1 && ! V_2 )
return 0 ;
if ( ! V_1 )
return - 1 ;
return + 1 ;
}
V_5 = V_6 = 0 ;
while ( 1 ) {
V_7 = V_1 [ V_5 ] ; V_8 = V_2 [ V_6 ] ;
while ( F_3 ( V_7 ) )
V_7 = V_1 [ ++ V_5 ] ;
while ( F_3 ( V_8 ) )
V_8 = V_2 [ ++ V_6 ] ;
if ( F_1 ( V_7 ) && F_1 ( V_8 ) ) {
V_9 = ( V_7 == '0' || V_8 == '0' ) ;
if ( V_9 ) {
if ( ( V_10 = F_8 ( V_1 + V_5 , V_2 + V_6 ) ) != 0 )
return V_10 ;
} else {
if ( ( V_10 = F_7 ( V_1 + V_5 , V_2 + V_6 ) ) != 0 )
return V_10 ;
}
}
if ( ! V_7 && ! V_8 ) {
return 0 ;
}
if ( V_4 ) {
V_7 = F_5 ( V_7 ) ;
V_8 = F_5 ( V_8 ) ;
}
if ( V_7 < V_8 )
return - 1 ;
else if ( V_7 > V_8 )
return + 1 ;
++ V_5 ; ++ V_6 ;
}
}
int F_10 ( T_1 const * V_1 , T_1 const * V_2 )
{
return F_9 ( V_1 , V_2 , 0 ) ;
}
int F_11 ( T_1 const * V_1 , T_1 const * V_2 )
{
return F_9 ( V_1 , V_2 , 1 ) ;
}
