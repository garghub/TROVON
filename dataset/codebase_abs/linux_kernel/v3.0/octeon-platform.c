static int T_1 F_1 ( void )
{
union V_1 V_2 ;
unsigned long V_3 , V_4 , V_5 ;
struct V_6 * V_7 ;
struct V_8 V_9 [ 3 ] ;
unsigned int V_10 ;
int V_11 ;
int V_12 = 0 ;
V_3 = 0 ;
if ( V_13 -> V_14 == 1
&& V_13 -> V_15 >= 1 ) {
if ( V_13 -> V_16 )
V_3 =
V_13 -> V_16 ;
} else {
V_3 = 0x1d000800 ;
}
if ( ! V_3 )
return V_12 ;
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ ) {
V_2 . V_17 = F_2 ( F_3 ( V_11 ) ) ;
V_4 = V_2 . V_18 . V_19 << 16 ;
V_5 = ( V_2 . V_18 . V_20 + 1 ) << 16 ;
if ( V_2 . V_18 . V_21 && V_3 >= V_4
&& V_3 < V_4 + V_5 )
break;
}
if ( V_11 >= 7 ) {
goto V_22;
}
V_23 . V_24 = V_11 ;
V_23 . V_25 = V_2 . V_18 . V_26 ;
V_23 . V_27 = V_3 - V_4 ;
memset ( V_9 , 0 , sizeof( V_9 ) ) ;
V_10 = 0 ;
V_9 [ V_10 ] . V_28 = V_29 ;
V_9 [ V_10 ] . V_30 = V_4 ;
V_9 [ V_10 ] . V_31 = V_4 + V_5 - 1 ;
V_10 ++ ;
if ( ! ( V_3 & 0xfffful ) ) {
V_2 . V_17 =
F_2 ( F_3 ( V_11 + 1 ) ) ;
V_4 = V_2 . V_18 . V_19 << 16 ;
V_5 = ( V_2 . V_18 . V_20 + 1 ) << 16 ;
if ( ! V_2 . V_18 . V_21 )
goto V_22;
V_9 [ V_10 ] . V_28 = V_29 ;
V_9 [ V_10 ] . V_30 = V_4 ;
V_9 [ V_10 ] . V_31 = V_4 + V_5 - 1 ;
V_10 ++ ;
V_23 . V_32 = 0 ;
V_9 [ V_10 ] . V_28 = V_33 ;
V_9 [ V_10 ] . V_30 = V_34 ;
V_9 [ V_10 ] . V_31 = V_34 ;
V_10 ++ ;
} else {
V_23 . V_32 = - 1 ;
}
V_7 = F_4 ( L_1 , - 1 ) ;
if ( ! V_7 ) {
V_12 = - V_35 ;
goto V_22;
}
V_7 -> V_36 . V_37 = & V_23 ;
V_12 = F_5 ( V_7 , V_9 , V_10 ) ;
if ( V_12 )
goto V_38;
V_12 = F_6 ( V_7 ) ;
if ( V_12 )
goto V_38;
return V_12 ;
V_38:
F_7 ( V_7 ) ;
V_22:
return V_12 ;
}
static int T_1 F_8 ( void )
{
struct V_6 * V_7 ;
int V_12 = 0 ;
struct V_8 V_39 [] = {
{
. V_28 = V_29 ,
. V_30 = F_9 ( V_40 ) ,
. V_31 = F_9 ( V_40 ) + 0xf
} , {
. V_28 = V_29 ,
. V_30 = F_10 ( 8 , 0 ) ,
. V_31 = F_10 ( 8 , 0 ) + 0x7
}
} ;
V_7 = F_4 ( L_2 , - 1 ) ;
if ( ! V_7 ) {
V_12 = - V_35 ;
goto V_22;
}
V_12 = F_5 ( V_7 , V_39 ,
F_11 ( V_39 ) ) ;
if ( V_12 )
goto V_38;
V_12 = F_6 ( V_7 ) ;
if ( V_12 )
goto V_38;
return V_12 ;
V_38:
F_7 ( V_7 ) ;
V_22:
return V_12 ;
}
static int T_1 F_12 ( void )
{
return F_13 ( 0 , V_41 ,
F_11 ( V_41 ) ) ;
}
static int T_1 F_14 ( void )
{
struct V_6 * V_7 ;
int V_12 = 0 ;
int V_42 , V_43 ;
struct V_8 V_44 [] = {
{
. V_28 = V_29 ,
} , {
. V_28 = V_33 ,
}
} ;
if ( F_15 ( V_45 ) || F_15 ( V_46 ) )
V_43 = 2 ;
else
V_43 = 1 ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ ) {
V_47 [ V_42 ] . V_48 = F_16 () ;
V_47 [ V_42 ] . V_49 = 100000 ;
V_7 = F_4 ( L_3 , V_42 ) ;
if ( ! V_7 ) {
V_12 = - V_35 ;
goto V_22;
}
V_7 -> V_36 . V_37 = V_47 + V_42 ;
V_44 [ 0 ] . V_30 =
V_50 + ( V_42 * V_51 ) ;
V_44 [ 0 ] . V_31 = V_44 [ 0 ] . V_30 + 0x1f ;
switch ( V_42 ) {
case 0 :
V_44 [ 1 ] . V_30 = V_52 ;
V_44 [ 1 ] . V_31 = V_52 ;
break;
case 1 :
V_44 [ 1 ] . V_30 = V_53 ;
V_44 [ 1 ] . V_31 = V_53 ;
break;
default:
F_17 () ;
}
V_12 = F_5 ( V_7 ,
V_44 ,
F_11 ( V_44 ) ) ;
if ( V_12 )
goto V_38;
V_12 = F_6 ( V_7 ) ;
if ( V_12 )
goto V_38;
}
return V_12 ;
V_38:
F_7 ( V_7 ) ;
V_22:
return V_12 ;
}
static int T_1 F_18 ( void )
{
struct V_6 * V_7 ;
int V_12 = 0 ;
if ( F_19 () )
return 0 ;
V_7 = F_4 ( L_4 , 0 ) ;
if ( ! V_7 ) {
V_12 = - V_35 ;
goto V_22;
}
V_12 = F_6 ( V_7 ) ;
if ( V_12 )
goto V_38;
return V_12 ;
V_38:
F_7 ( V_7 ) ;
V_22:
return V_12 ;
}
static int T_1 F_20 ( void )
{
struct V_6 * V_7 ;
int V_12 = 0 ;
int V_42 , V_43 ;
struct V_8 V_54 = {
. V_28 = V_33 ,
. V_30 = - 1 ,
. V_31 = - 1
} ;
if ( ! F_15 ( V_45 ) && ! F_15 ( V_46 ) )
return 0 ;
if ( F_15 ( V_45 ) )
V_43 = 1 ;
else
V_43 = 2 ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ ) {
V_7 = F_4 ( L_5 , V_42 ) ;
if ( ! V_7 ) {
V_12 = - V_35 ;
goto V_22;
}
V_7 -> V_36 . V_55 = F_21 ( 64 ) ;
V_7 -> V_36 . V_56 = & V_7 -> V_36 . V_55 ;
switch ( V_42 ) {
case 0 :
V_54 . V_30 = V_57 ;
break;
case 1 :
V_54 . V_30 = V_58 ;
break;
default:
F_17 () ;
}
V_54 . V_31 = V_54 . V_30 ;
V_12 = F_5 ( V_7 , & V_54 , 1 ) ;
if ( V_12 )
goto V_38;
V_12 = F_6 ( V_7 ) ;
if ( V_12 )
goto V_38;
}
return V_12 ;
V_38:
F_7 ( V_7 ) ;
V_22:
return V_12 ;
}
static int T_1 F_22 ( void )
{
struct V_6 * V_7 ;
int V_12 = 0 ;
struct V_8 V_59 [] = {
{
. V_28 = V_29 ,
} , {
. V_28 = V_33 ,
}
} ;
if ( ! F_15 ( V_60 ) )
return 0 ;
if ( F_19 () || F_23 () )
return 0 ;
V_7 = F_4 ( L_6 , 0 ) ;
if ( ! V_7 ) {
V_12 = - V_35 ;
goto V_22;
}
V_59 [ 0 ] . V_30 = 0x00016F0000000000ULL ;
V_59 [ 0 ] . V_31 = V_59 [ 0 ] . V_30 + 0x100 ;
V_59 [ 1 ] . V_30 = V_61 ;
V_59 [ 1 ] . V_31 = V_61 ;
V_12 = F_5 ( V_7 , V_59 ,
F_11 ( V_59 ) ) ;
if ( V_12 )
goto V_38;
V_12 = F_6 ( V_7 ) ;
if ( V_12 )
goto V_38;
return V_12 ;
V_38:
F_7 ( V_7 ) ;
V_22:
return V_12 ;
}
static int T_1 F_24 ( void )
{
struct V_6 * V_7 ;
int V_12 = 0 ;
struct V_8 V_59 [] = {
{
. V_28 = V_29 ,
} , {
. V_28 = V_33 ,
}
} ;
if ( ! F_15 ( V_60 ) )
return 0 ;
if ( F_19 () || F_23 () )
return 0 ;
V_7 = F_4 ( L_7 , 0 ) ;
if ( ! V_7 ) {
V_12 = - V_35 ;
goto V_22;
}
V_59 [ 0 ] . V_30 = 0x00016F0000000400ULL ;
V_59 [ 0 ] . V_31 = V_59 [ 0 ] . V_30 + 0x100 ;
V_59 [ 1 ] . V_30 = V_61 ;
V_59 [ 1 ] . V_31 = V_61 ;
V_12 = F_5 ( V_7 , V_59 ,
F_11 ( V_59 ) ) ;
if ( V_12 )
goto V_38;
V_12 = F_6 ( V_7 ) ;
if ( V_12 )
goto V_38;
return V_12 ;
V_38:
F_7 ( V_7 ) ;
V_22:
return V_12 ;
}
