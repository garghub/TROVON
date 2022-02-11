void F_1 ( void )
{
F_2 ( V_1 ) ;
F_3 () ;
}
void F_4 ( char * V_2 )
{
F_5 ( & V_3 , V_4 , V_2 ) ;
V_5 = V_6 ;
F_6 () ;
F_7 () ;
}
int F_8 ( struct V_7 * V_8 )
{
return F_9 ( & V_3 , V_8 ) ;
}
int F_10 ( struct V_7 * V_8 )
{
return F_11 ( & V_3 , V_8 ) ;
}
int F_12 ( struct V_7 * V_8 )
{
return F_13 ( & V_9 , V_8 ) ;
}
int F_14 ( struct V_7 * V_8 )
{
return F_15 ( & V_9 , V_8 ) ;
}
void F_16 ( char * V_2 )
{
F_17 ( & V_9 , V_10 , V_2 ) ;
}
void F_18 ( void )
{
int V_11 = V_12 ;
F_19 () ;
if ( ! F_20 ( V_11 ) )
V_11 = F_21 ( V_13 ) ;
V_14 -> V_15 |= V_16 ;
F_22 ( V_14 , F_23 ( V_11 ) ) ;
}
void F_24 ( char * V_2 )
{
F_4 ( V_2 ) ;
F_18 () ;
F_25 () ;
if ( ! V_2 )
F_26 ( L_1 ) ;
else
F_26 ( L_2 , V_2 ) ;
F_2 ( V_17 ) ;
F_27 ( V_2 ) ;
}
static void F_28 ( enum V_18 V_19 )
{
F_5 ( & V_3 ,
( V_19 == V_20 ) ? V_21 : V_22 , NULL ) ;
V_5 = V_19 ;
F_6 () ;
F_7 () ;
}
void F_29 ( void )
{
F_28 ( V_20 ) ;
F_18 () ;
F_25 () ;
F_26 ( L_3 ) ;
F_2 ( V_23 ) ;
F_30 () ;
}
void F_31 ( void )
{
F_28 ( V_24 ) ;
if ( V_25 )
V_25 () ;
F_18 () ;
F_25 () ;
F_26 ( L_4 ) ;
F_2 ( V_26 ) ;
F_32 () ;
}
static void F_33 ( struct V_27 * V_28 )
{
F_24 ( NULL ) ;
}
void F_34 ( void )
{
static F_35 ( V_29 , F_33 ) ;
if ( V_30 )
F_36 ( & V_29 ) ;
else
F_37 ( V_31 , 1 ) ;
}
static int F_38 ( const char * V_2 )
{
char * * V_32 ;
static char * V_33 [] = {
L_5 ,
L_6 ,
NULL
} ;
int V_34 ;
V_32 = F_39 ( V_35 , V_2 , NULL ) ;
if ( V_32 ) {
V_34 = F_40 ( V_32 [ 0 ] , V_32 , V_33 , V_36 ) ;
F_41 ( V_32 ) ;
} else {
V_34 = - V_37 ;
}
return V_34 ;
}
static int F_42 ( void )
{
int V_34 ;
V_34 = F_38 ( V_38 ) ;
if ( V_34 ) {
F_43 ( L_7 ) ;
F_44 () ;
F_24 ( NULL ) ;
}
return V_34 ;
}
static int F_45 ( bool V_39 )
{
int V_34 ;
V_34 = F_38 ( V_40 ) ;
if ( V_34 && V_39 ) {
F_43 ( L_8 ) ;
F_44 () ;
F_31 () ;
}
return V_34 ;
}
static void F_46 ( struct V_27 * V_41 )
{
F_45 ( V_42 ) ;
}
void F_47 ( bool V_39 )
{
if ( V_39 )
V_42 = true ;
F_36 ( & V_43 ) ;
}
static void F_48 ( struct V_27 * V_41 )
{
F_42 () ;
}
void F_49 ( void )
{
F_36 ( & V_44 ) ;
}
static int T_1 F_50 ( char * V_45 )
{
for (; ; ) {
V_46 = 0 ;
switch ( * V_45 ) {
case 'w' :
V_10 = V_47 ;
break;
case 'c' :
V_10 = V_48 ;
break;
case 'h' :
V_10 = V_49 ;
break;
case 's' :
{
int V_50 ;
if ( isdigit ( * ( V_45 + 1 ) ) ) {
V_50 = F_51 ( V_45 + 1 , 0 , & V_12 ) ;
if ( V_50 )
return V_50 ;
} else if ( V_45 [ 1 ] == 'm' && V_45 [ 2 ] == 'p' &&
isdigit ( * ( V_45 + 3 ) ) ) {
V_50 = F_51 ( V_45 + 3 , 0 , & V_12 ) ;
if ( V_50 )
return V_50 ;
} else
V_10 = V_51 ;
break;
}
case 'g' :
V_10 = V_52 ;
break;
case 'b' :
case 'a' :
case 'k' :
case 't' :
case 'e' :
case 'p' :
V_53 = * V_45 ;
break;
case 'f' :
V_54 = 1 ;
break;
}
V_45 = strchr ( V_45 , ',' ) ;
if ( V_45 )
V_45 ++ ;
else
break;
}
return 1 ;
}
