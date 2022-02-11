static int F_1 ( int V_1 , int V_2 , int V_3 ,
enum V_4 V_5 )
{
int V_6 ;
for ( V_6 = V_2 ; V_6 <= V_3 ; V_6 ++ ) {
if ( ( V_7 [ V_1 ] [ V_6 ] != V_8 )
&& ( V_7 [ V_1 ] [ V_6 ] != V_9 )
&& ( V_7 [ V_1 ] [ V_6 ] != V_5 ) ) {
#ifdef F_2
F_3 ( L_1 ) ;
#endif
return - V_10 ;
}
}
for ( V_6 = V_2 ; V_6 <= V_3 ; V_6 ++ )
V_7 [ V_1 ] [ V_6 ] = V_5 ;
F_4 ( V_1 ) ;
return 0 ;
}
static int F_5 ( void )
{
static int V_11 ;
if ( ! V_11 ) {
T_1 V_12 = F_6 ( V_13 , V_14 , V_15 ) ;
V_11 = 1 ;
F_7 ( V_13 , V_14 , V_16 , 0 ) ;
V_12 . V_17 = V_12 . V_18 = V_12 . V_19 = V_12 . V_20 =
V_12 . V_21 = V_12 . V_22 = V_12 . V_23 = V_12 . V_24 = V_25 ;
F_8 ( V_13 , V_14 , V_15 , V_12 ) ;
F_1 ( V_26 , 0 , V_27 - 1 , V_9 ) ;
F_1 ( V_28 , 0 , V_27 - 1 , V_9 ) ;
F_1 ( V_29 , 0 , V_27 - 1 , V_9 ) ;
F_1 ( V_30 , 0 , V_27 - 1 , V_9 ) ;
}
return 0 ;
}
int F_9 ( int V_1 , int V_2 , int V_3 ,
enum V_4 V_5 )
{
unsigned long V_31 ;
int V_32 ;
F_5 () ;
if ( V_1 > V_33 || V_1 < 0 )
return - V_34 ;
F_10 ( & V_35 , V_31 ) ;
V_32 = F_1 ( V_1 , V_2 , V_3 , V_5 ) ;
F_11 ( & V_35 , V_31 ) ;
return V_32 ;
}
int F_12 ( enum V_36 V_37 )
{
int V_32 = - V_34 ;
char V_38 [ sizeof V_7 ] ;
unsigned long V_31 ;
T_2 V_39 ;
F_10 ( & V_35 , V_31 ) ;
memcpy ( V_38 , V_7 , sizeof V_7 ) ;
F_5 () ;
V_39 = F_6 ( V_13 , V_14 , V_16 ) ;
switch ( V_37 ) {
case V_40 :
V_32 = F_1 ( V_28 , 4 , 7 , V_41 ) ;
V_39 . V_42 = V_25 ;
break;
case V_43 :
V_32 = F_1 ( V_28 , 8 , 11 , V_41 ) ;
V_39 . V_44 = V_25 ;
break;
case V_45 :
V_32 = F_1 ( V_28 , 12 , 15 , V_41 ) ;
V_39 . V_46 = V_25 ;
break;
case V_47 :
V_32 = F_1 ( V_28 , 0 , 3 , V_41 ) ;
V_32 |= F_1 ( V_28 , 16 , 16 , V_41 ) ;
V_39 . V_48 = V_25 ;
break;
case V_49 :
V_32 = F_1 ( V_29 , 0 , 4 , V_41 ) ;
V_39 . V_50 = V_25 ;
break;
case V_51 :
V_32 = F_1 ( V_29 , 5 , 7 , V_41 ) ;
V_32 |= F_1 ( V_29 , 15 , 17 , V_41 ) ;
V_39 . V_52 = V_25 ;
break;
case V_53 :
V_32 = F_1 ( V_29 , 0 , 4 , V_41 ) ;
V_32 |= F_1 ( V_30 , 17 , 17 , V_41 ) ;
V_39 . V_54 = V_25 ;
break;
case V_55 :
V_32 = F_1 ( V_28 , 11 , 15 , V_41 ) ;
V_32 |= F_1 ( V_30 , 3 , 3 , V_41 ) ;
V_39 . V_56 = V_25 ;
break;
case V_57 :
V_32 = F_1 ( V_28 , 8 , 10 , V_41 ) ;
V_32 |= F_1 ( V_28 , 0 , 2 , V_41 ) ;
V_39 . V_56 = V_25 ;
break;
case V_58 :
V_32 = F_1 ( V_26 , 0 , 15 , V_41 ) ;
V_32 |= F_1 ( V_29 , 8 , 15 , V_41 ) ;
V_39 . V_59 = V_25 ;
break;
case V_60 :
V_32 = F_1 ( V_30 , 0 , 17 , V_41 ) ;
V_39 . V_61 = V_25 ;
V_39 . V_62 = V_25 ;
break;
case V_63 :
V_32 = F_1 ( V_28 , 16 , 16 , V_41 ) ;
V_39 . V_64 = V_25 ;
F_11 ( & V_35 , V_31 ) ;
return V_32 ;
}
if ( ! V_32 )
F_8 ( V_13 , V_14 , V_16 , V_39 ) ;
else
memcpy ( V_7 , V_38 , sizeof V_7 ) ;
F_11 ( & V_35 , V_31 ) ;
return V_32 ;
}
void F_4 ( int V_1 )
{
int V_6 ;
int V_65 = 0 ;
int V_66 = 0 ;
for ( V_6 = 0 ; V_6 < V_27 ; V_6 ++ ) {
if ( V_7 [ V_1 ] [ V_6 ] == V_9 )
V_65 |= ( 1 << V_6 ) ;
else if ( V_7 [ V_1 ] [ V_6 ] == V_67 )
V_66 |= ( 1 << V_6 ) ;
}
F_13 ( int , V_14 + V_68 + 8 * V_1 ,
V_65 ) ;
F_13 ( int , V_14 + V_69 + 8 * V_1 ,
V_66 ) ;
#ifdef F_2
F_14 () ;
#endif
}
static int F_15 ( int V_1 , int V_2 , int V_3 )
{
int V_6 ;
for ( V_6 = V_2 ; V_6 <= V_3 ; V_6 ++ )
V_7 [ V_1 ] [ V_6 ] = V_8 ;
F_4 ( V_1 ) ;
return 0 ;
}
int F_16 ( int V_1 , int V_2 , int V_3 )
{
unsigned long V_31 ;
F_5 () ;
if ( V_1 > V_33 || V_1 < 0 )
return - V_34 ;
F_10 ( & V_35 , V_31 ) ;
F_15 ( V_1 , V_2 , V_3 ) ;
F_11 ( & V_35 , V_31 ) ;
return 0 ;
}
int F_17 ( enum V_36 V_37 )
{
int V_32 = - V_34 ;
char V_38 [ sizeof V_7 ] ;
unsigned long V_31 ;
T_2 V_39 ;
F_10 ( & V_35 , V_31 ) ;
memcpy ( V_38 , V_7 , sizeof V_7 ) ;
F_5 () ;
V_39 = F_6 ( V_13 , V_14 , V_16 ) ;
switch ( V_37 ) {
case V_40 :
V_32 = F_15 ( V_28 , 4 , 7 ) ;
V_39 . V_42 = V_70 ;
break;
case V_43 :
V_32 = F_15 ( V_28 , 8 , 11 ) ;
V_39 . V_44 = V_70 ;
break;
case V_45 :
V_32 = F_15 ( V_28 , 12 , 15 ) ;
V_39 . V_46 = V_70 ;
break;
case V_47 :
V_32 = F_15 ( V_28 , 0 , 3 ) ;
V_32 |= F_15 ( V_28 , 16 , 16 ) ;
V_39 . V_48 = V_70 ;
break;
case V_49 :
V_32 = F_15 ( V_29 , 0 , 4 ) ;
V_39 . V_50 = V_70 ;
break;
case V_51 :
V_32 = F_15 ( V_29 , 5 , 7 ) ;
V_32 |= F_15 ( V_29 , 15 , 17 ) ;
V_39 . V_52 = V_70 ;
break;
case V_53 :
V_32 = F_15 ( V_29 , 0 , 4 ) ;
V_32 |= F_15 ( V_30 , 17 , 17 ) ;
V_39 . V_54 = V_70 ;
break;
case V_55 :
V_32 = F_15 ( V_28 , 11 , 15 ) ;
V_32 |= F_15 ( V_30 , 3 , 3 ) ;
V_39 . V_56 = V_70 ;
break;
case V_57 :
V_32 = F_15 ( V_28 , 8 , 10 ) ;
V_32 |= F_15 ( V_28 , 0 , 2 ) ;
V_39 . V_56 = V_70 ;
break;
case V_58 :
V_32 = F_15 ( V_26 , 0 , 15 ) ;
V_32 |= F_15 ( V_29 , 8 , 15 ) ;
V_39 . V_59 = V_70 ;
break;
case V_60 :
V_32 = F_15 ( V_30 , 0 , 17 ) ;
V_39 . V_61 = V_70 ;
V_39 . V_62 = V_70 ;
break;
case V_63 :
V_32 = F_15 ( V_28 , 16 , 16 ) ;
V_39 . V_64 = V_70 ;
F_11 ( & V_35 , V_31 ) ;
return V_32 ;
}
if ( ! V_32 )
F_8 ( V_13 , V_14 , V_16 , V_39 ) ;
else
memcpy ( V_7 , V_38 , sizeof V_7 ) ;
F_11 ( & V_35 , V_31 ) ;
return V_32 ;
}
static void F_14 ( void )
{
int V_6 , V_71 ;
F_5 () ;
for ( V_6 = 0 ; V_6 < V_33 ; V_6 ++ ) {
F_18 ( V_72 L_2 , 'B' + V_6 ) ;
for ( V_71 = 0 ; V_71 < V_27 ; V_71 ++ )
F_18 ( V_72 L_3 , V_71 , V_7 [ V_6 ] [ V_71 ] ) ;
}
}
