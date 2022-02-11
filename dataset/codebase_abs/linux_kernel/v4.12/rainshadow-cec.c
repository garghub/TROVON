static void F_1 ( struct V_1 * V_1 )
{
struct V_2 V_3 = {} ;
const char * V_4 = V_1 -> V_4 + 3 ;
int V_5 = - 1 ;
for (; * V_4 ; V_4 ++ ) {
if ( ! isxdigit ( * V_4 ) )
continue;
if ( isxdigit ( V_4 [ 0 ] ) && isxdigit ( V_4 [ 1 ] ) ) {
if ( V_3 . V_6 == V_7 )
break;
if ( F_2 ( V_3 . V_3 + V_3 . V_6 , V_4 , 1 ) )
continue;
V_3 . V_6 ++ ;
V_4 ++ ;
continue;
}
if ( ! V_4 [ 1 ] )
V_5 = F_3 ( V_4 [ 0 ] ) ;
break;
}
if ( V_1 -> V_4 [ 0 ] == 'R' ) {
if ( V_5 == 1 || V_5 == 2 )
F_4 ( V_1 -> V_8 , & V_3 ) ;
return;
}
switch ( V_5 ) {
case 1 :
F_5 ( V_1 -> V_8 , V_9 ,
0 , 0 , 0 , 0 ) ;
break;
case 2 :
F_5 ( V_1 -> V_8 , V_10 ,
0 , 1 , 0 , 0 ) ;
break;
default:
F_5 ( V_1 -> V_8 , V_11 ,
0 , 0 , 0 , 1 ) ;
break;
}
}
static void F_6 ( struct V_12 * V_13 )
{
struct V_1 * V_1 =
F_7 ( V_13 , struct V_1 , V_13 ) ;
while ( true ) {
unsigned long V_14 ;
bool V_15 = false ;
char V_16 ;
F_8 ( & V_1 -> V_17 , V_14 ) ;
V_15 = V_1 -> V_18 == 0 ;
if ( V_1 -> V_18 ) {
V_16 = V_1 -> V_19 [ V_1 -> V_20 ] ;
V_1 -> V_18 -- ;
V_1 -> V_20 = ( V_1 -> V_20 + 1 ) & 0xff ;
}
F_9 ( & V_1 -> V_17 , V_14 ) ;
if ( V_15 )
break;
if ( ! V_1 -> V_21 && V_16 != '?' )
continue;
switch ( V_16 ) {
case '\r' :
V_1 -> V_4 [ V_1 -> V_22 ] = '\0' ;
F_10 ( V_1 -> V_23 , L_1 , V_1 -> V_4 ) ;
if ( ! memcmp ( V_1 -> V_4 , L_2 , 3 ) ||
! memcmp ( V_1 -> V_4 , L_3 , 3 ) ) {
F_1 ( V_1 ) ;
} else {
strcpy ( V_1 -> V_24 , V_1 -> V_4 ) ;
F_11 ( & V_1 -> V_25 ) ;
}
V_1 -> V_22 = 0 ;
V_1 -> V_21 = false ;
break;
case '\n' :
V_1 -> V_22 = 0 ;
V_1 -> V_21 = false ;
break;
case '?' :
V_1 -> V_22 = 0 ;
V_1 -> V_21 = true ;
break;
default:
if ( V_1 -> V_22 >= V_26 - 1 ) {
F_10 ( V_1 -> V_23 ,
L_4 , V_1 -> V_22 ) ;
V_1 -> V_22 = 0 ;
}
V_1 -> V_4 [ V_1 -> V_22 ++ ] = V_16 ;
break;
}
}
}
static T_1 F_12 ( struct V_27 * V_27 , unsigned char V_16 ,
unsigned int V_14 )
{
struct V_1 * V_1 = F_13 ( V_27 ) ;
if ( V_1 -> V_18 == V_26 ) {
F_14 ( V_1 -> V_23 , L_5 ) ;
return V_28 ;
}
F_15 ( & V_1 -> V_17 ) ;
V_1 -> V_18 ++ ;
V_1 -> V_19 [ V_1 -> V_29 ] = V_16 ;
V_1 -> V_29 = ( V_1 -> V_29 + 1 ) & 0xff ;
F_16 ( & V_1 -> V_17 ) ;
F_17 ( & V_1 -> V_13 ) ;
return V_28 ;
}
static void F_18 ( struct V_27 * V_27 )
{
struct V_1 * V_1 = F_13 ( V_27 ) ;
F_19 ( & V_1 -> V_13 ) ;
F_20 ( V_1 -> V_8 ) ;
F_21 ( & V_27 -> V_23 , L_6 ) ;
F_22 ( V_27 ) ;
F_23 ( V_27 , NULL ) ;
F_24 ( V_1 ) ;
}
static int F_25 ( struct V_1 * V_1 , const char * V_30 )
{
int V_31 = F_26 ( V_1 -> V_27 , '!' ) ;
F_10 ( V_1 -> V_23 , L_7 , V_30 ) ;
while ( ! V_31 && * V_30 )
V_31 = F_26 ( V_1 -> V_27 , * V_30 ++ ) ;
if ( ! V_31 )
V_31 = F_26 ( V_1 -> V_27 , '~' ) ;
return V_31 ;
}
static int F_27 ( struct V_1 * V_1 ,
const char * V_4 , const char * V_32 )
{
int V_31 ;
F_28 ( & V_1 -> V_25 ) ;
F_29 ( & V_1 -> V_33 ) ;
V_31 = F_25 ( V_1 , V_4 ) ;
if ( V_31 )
goto V_31;
if ( ! F_30 ( & V_1 -> V_25 , V_34 ) ) {
V_31 = - V_35 ;
goto V_31;
}
if ( V_32 && strncmp ( V_1 -> V_24 , V_32 , strlen ( V_32 ) ) ) {
F_10 ( V_1 -> V_23 ,
L_8 ,
V_4 , V_1 -> V_24 , V_32 ) ;
V_31 = - V_36 ;
}
V_31:
F_31 ( & V_1 -> V_33 ) ;
return V_31 ;
}
static int F_32 ( struct V_1 * V_1 , struct V_27 * V_27 ,
struct V_37 * V_38 , T_2 * V_39 )
{
int V_31 ;
V_31 = F_27 ( V_1 , L_9 , L_10 ) ;
if ( V_31 )
return V_31 ;
F_21 ( V_1 -> V_23 , L_11 , V_1 -> V_24 + 4 ) ;
V_31 = F_27 ( V_1 , L_12 , L_13 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_27 ( V_1 , L_14 , L_15 ) ;
if ( V_31 )
return V_31 ;
return F_27 ( V_1 , L_16 , L_17 ) ;
}
static int F_33 ( struct V_40 * V_8 , bool V_41 )
{
return 0 ;
}
static int F_34 ( struct V_40 * V_8 , T_3 V_42 )
{
struct V_1 * V_1 = F_35 ( V_8 ) ;
T_3 V_4 [ 16 ] ;
if ( V_42 == V_43 )
V_42 = V_44 ;
snprintf ( V_4 , sizeof( V_4 ) , L_18 , V_42 ) ;
return F_27 ( V_1 , V_4 , L_17 ) ;
}
static int F_36 ( struct V_40 * V_8 , T_3 V_45 ,
T_4 V_46 , struct V_2 * V_3 )
{
struct V_1 * V_1 = F_35 ( V_8 ) ;
char V_4 [ 2 * V_7 + 16 ] ;
unsigned int V_47 ;
int V_31 ;
if ( V_3 -> V_6 == 1 ) {
snprintf ( V_4 , sizeof( V_4 ) , L_19 , F_37 ( V_3 ) ) ;
} else {
char V_48 [ 3 ] ;
snprintf ( V_4 , sizeof( V_4 ) , L_20 ,
F_37 ( V_3 ) , V_3 -> V_3 [ 1 ] ) ;
for ( V_47 = 2 ; V_47 < V_3 -> V_6 ; V_47 ++ ) {
snprintf ( V_48 , sizeof( V_48 ) , L_21 , V_3 -> V_3 [ V_47 ] ) ;
strncat ( V_4 , V_48 , sizeof( V_4 ) ) ;
}
}
F_29 ( & V_1 -> V_33 ) ;
V_31 = F_25 ( V_1 , V_4 ) ;
F_31 ( & V_1 -> V_33 ) ;
return V_31 ;
}
static int F_38 ( struct V_27 * V_27 , struct V_49 * V_50 )
{
T_4 V_51 = V_52 | V_53 | V_54 |
V_55 | V_56 | V_57 ;
struct V_1 * V_1 ;
int V_31 = - V_58 ;
struct V_37 V_38 = {} ;
T_2 V_39 = V_59 ;
V_1 = F_39 ( sizeof( * V_1 ) , V_60 ) ;
if ( ! V_1 )
return - V_58 ;
V_1 -> V_27 = V_27 ;
V_1 -> V_8 = F_40 ( & V_61 , V_1 ,
L_22 , V_51 , 1 ) ;
V_31 = F_41 ( V_1 -> V_8 ) ;
if ( V_31 < 0 )
goto V_62;
V_1 -> V_23 = & V_27 -> V_23 ;
F_23 ( V_27 , V_1 ) ;
F_42 ( & V_1 -> V_13 , F_6 ) ;
F_43 ( & V_1 -> V_33 ) ;
F_44 ( & V_1 -> V_17 ) ;
V_31 = F_45 ( V_27 , V_50 ) ;
if ( V_31 )
goto V_63;
V_31 = F_32 ( V_1 , V_27 , & V_38 , & V_39 ) ;
if ( V_31 )
goto V_64;
V_31 = F_46 ( V_1 -> V_8 , & V_27 -> V_23 ) ;
if ( V_31 < 0 )
goto V_64;
V_1 -> V_23 = & V_1 -> V_8 -> V_65 . V_23 ;
return 0 ;
V_64:
F_22 ( V_27 ) ;
V_63:
F_47 ( V_1 -> V_8 ) ;
F_23 ( V_27 , NULL ) ;
V_62:
F_24 ( V_1 ) ;
return V_31 ;
}
