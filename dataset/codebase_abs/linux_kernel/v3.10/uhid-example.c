static int F_1 ( int V_1 , const struct V_2 * V_3 )
{
T_1 V_4 ;
V_4 = F_2 ( V_1 , V_3 , sizeof( * V_3 ) ) ;
if ( V_4 < 0 ) {
fprintf ( V_5 , L_1 ) ;
return - V_6 ;
} else if ( V_4 != sizeof( * V_3 ) ) {
fprintf ( V_5 , L_2 ,
V_4 , sizeof( V_3 ) ) ;
return - V_7 ;
} else {
return 0 ;
}
}
static int F_3 ( int V_1 )
{
struct V_2 V_3 ;
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
V_3 . type = V_8 ;
strcpy ( ( char * ) V_3 . V_9 . F_3 . V_10 , L_3 ) ;
V_3 . V_9 . F_3 . V_11 = V_12 ;
V_3 . V_9 . F_3 . V_13 = sizeof( V_12 ) ;
V_3 . V_9 . F_3 . V_14 = V_15 ;
V_3 . V_9 . F_3 . V_16 = 0x15d9 ;
V_3 . V_9 . F_3 . V_17 = 0x0a37 ;
V_3 . V_9 . F_3 . V_18 = 0 ;
V_3 . V_9 . F_3 . V_19 = 0 ;
return F_1 ( V_1 , & V_3 ) ;
}
static void F_4 ( int V_1 )
{
struct V_2 V_3 ;
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
V_3 . type = V_20 ;
F_1 ( V_1 , & V_3 ) ;
}
static int F_5 ( int V_1 )
{
struct V_2 V_3 ;
T_1 V_4 ;
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
V_4 = F_6 ( V_1 , & V_3 , sizeof( V_3 ) ) ;
if ( V_4 == 0 ) {
fprintf ( V_5 , L_4 ) ;
return - V_7 ;
} else if ( V_4 < 0 ) {
fprintf ( V_5 , L_5 ) ;
return - V_6 ;
} else if ( V_4 != sizeof( V_3 ) ) {
fprintf ( V_5 , L_6 ,
V_4 , sizeof( V_3 ) ) ;
return - V_7 ;
}
switch ( V_3 . type ) {
case V_21 :
fprintf ( V_5 , L_7 ) ;
break;
case V_22 :
fprintf ( V_5 , L_8 ) ;
break;
case V_23 :
fprintf ( V_5 , L_9 ) ;
break;
case V_24 :
fprintf ( V_5 , L_10 ) ;
break;
case V_25 :
fprintf ( V_5 , L_11 ) ;
break;
case V_26 :
fprintf ( V_5 , L_12 ) ;
break;
default:
fprintf ( V_5 , L_13 , V_3 . type ) ;
}
return 0 ;
}
static int F_7 ( int V_1 )
{
struct V_2 V_3 ;
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
V_3 . type = V_27 ;
V_3 . V_9 . V_28 . V_29 = 4 ;
if ( V_30 )
V_3 . V_9 . V_28 . V_31 [ 0 ] |= 0x1 ;
if ( V_32 )
V_3 . V_9 . V_28 . V_31 [ 0 ] |= 0x2 ;
if ( V_33 )
V_3 . V_9 . V_28 . V_31 [ 0 ] |= 0x4 ;
V_3 . V_9 . V_28 . V_31 [ 1 ] = V_34 ;
V_3 . V_9 . V_28 . V_31 [ 2 ] = V_35 ;
V_3 . V_9 . V_28 . V_31 [ 3 ] = V_36 ;
return F_1 ( V_1 , & V_3 ) ;
}
static int F_8 ( int V_1 )
{
char V_37 [ 128 ] ;
T_1 V_4 , V_38 ;
V_4 = F_6 ( V_39 , V_37 , sizeof( V_37 ) ) ;
if ( V_4 == 0 ) {
fprintf ( V_5 , L_14 ) ;
return - V_7 ;
} else if ( V_4 < 0 ) {
fprintf ( V_5 , L_15 ) ;
return - V_6 ;
}
for ( V_38 = 0 ; V_38 < V_4 ; ++ V_38 ) {
switch ( V_37 [ V_38 ] ) {
case '1' :
V_30 = ! V_30 ;
V_4 = F_7 ( V_1 ) ;
if ( V_4 )
return V_4 ;
break;
case '2' :
V_32 = ! V_32 ;
V_4 = F_7 ( V_1 ) ;
if ( V_4 )
return V_4 ;
break;
case '3' :
V_33 = ! V_33 ;
V_4 = F_7 ( V_1 ) ;
if ( V_4 )
return V_4 ;
break;
case 'a' :
V_34 = - 20 ;
V_4 = F_7 ( V_1 ) ;
V_34 = 0 ;
if ( V_4 )
return V_4 ;
break;
case 'd' :
V_34 = 20 ;
V_4 = F_7 ( V_1 ) ;
V_34 = 0 ;
if ( V_4 )
return V_4 ;
break;
case 'w' :
V_35 = - 20 ;
V_4 = F_7 ( V_1 ) ;
V_35 = 0 ;
if ( V_4 )
return V_4 ;
break;
case 's' :
V_35 = 20 ;
V_4 = F_7 ( V_1 ) ;
V_35 = 0 ;
if ( V_4 )
return V_4 ;
break;
case 'r' :
V_36 = 1 ;
V_4 = F_7 ( V_1 ) ;
V_36 = 0 ;
if ( V_4 )
return V_4 ;
break;
case 'f' :
V_36 = - 1 ;
V_4 = F_7 ( V_1 ) ;
V_36 = 0 ;
if ( V_4 )
return V_4 ;
break;
case 'q' :
return - V_40 ;
default:
fprintf ( V_5 , L_16 , V_37 [ V_38 ] ) ;
}
}
return 0 ;
}
int main ( int V_41 , char * * V_42 )
{
int V_1 ;
const char * V_43 = L_17 ;
struct V_44 V_45 [ 2 ] ;
int V_4 ;
struct V_46 V_47 ;
V_4 = F_9 ( V_39 , & V_47 ) ;
if ( V_4 ) {
fprintf ( V_5 , L_18 ) ;
} else {
V_47 . V_48 &= ~ V_49 ;
V_47 . V_50 [ V_51 ] = 1 ;
V_4 = F_10 ( V_39 , V_52 , & V_47 ) ;
if ( V_4 )
fprintf ( V_5 , L_19 ) ;
}
if ( V_41 >= 2 ) {
if ( ! strcmp ( V_42 [ 1 ] , L_20 ) || ! strcmp ( V_42 [ 1 ] , L_21 ) ) {
fprintf ( V_5 , L_22 , V_42 [ 0 ] , V_43 ) ;
return V_53 ;
} else {
V_43 = V_42 [ 1 ] ;
}
}
fprintf ( V_5 , L_23 , V_43 ) ;
V_1 = F_11 ( V_43 , V_54 | V_55 ) ;
if ( V_1 < 0 ) {
fprintf ( V_5 , L_24 , V_43 ) ;
return V_56 ;
}
fprintf ( V_5 , L_25 ) ;
V_4 = F_3 ( V_1 ) ;
if ( V_4 ) {
F_12 ( V_1 ) ;
return V_56 ;
}
V_45 [ 0 ] . V_1 = V_39 ;
V_45 [ 0 ] . V_57 = V_58 ;
V_45 [ 1 ] . V_1 = V_1 ;
V_45 [ 1 ] . V_57 = V_58 ;
fprintf ( V_5 , L_26 ) ;
while ( 1 ) {
V_4 = F_13 ( V_45 , 2 , - 1 ) ;
if ( V_4 < 0 ) {
fprintf ( V_5 , L_27 ) ;
break;
}
if ( V_45 [ 0 ] . V_59 & V_60 ) {
fprintf ( V_5 , L_28 ) ;
break;
}
if ( V_45 [ 1 ] . V_59 & V_60 ) {
fprintf ( V_5 , L_29 ) ;
break;
}
if ( V_45 [ 0 ] . V_59 & V_58 ) {
V_4 = F_8 ( V_1 ) ;
if ( V_4 )
break;
}
if ( V_45 [ 1 ] . V_59 & V_58 ) {
V_4 = F_5 ( V_1 ) ;
if ( V_4 )
break;
}
}
fprintf ( V_5 , L_30 ) ;
F_4 ( V_1 ) ;
return V_53 ;
}
