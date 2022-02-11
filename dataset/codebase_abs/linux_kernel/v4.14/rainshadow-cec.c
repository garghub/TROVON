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
F_5 ( V_1 -> V_8 , V_9 ) ;
break;
case 2 :
F_5 ( V_1 -> V_8 , V_10 ) ;
break;
default:
F_5 ( V_1 -> V_8 , V_11 ) ;
break;
}
}
static void F_6 ( struct V_12 * V_13 )
{
struct V_1 * V_1 =
F_7 ( V_13 , struct V_1 , V_13 ) ;
while ( true ) {
unsigned long V_14 ;
char V_15 ;
F_8 ( & V_1 -> V_16 , V_14 ) ;
if ( ! V_1 -> V_17 ) {
F_9 ( & V_1 -> V_16 , V_14 ) ;
break;
}
V_15 = V_1 -> V_18 [ V_1 -> V_19 ] ;
V_1 -> V_17 -- ;
V_1 -> V_19 = ( V_1 -> V_19 + 1 ) & 0xff ;
F_9 ( & V_1 -> V_16 , V_14 ) ;
if ( ! V_1 -> V_20 && V_15 != '?' )
continue;
switch ( V_15 ) {
case '\r' :
V_1 -> V_4 [ V_1 -> V_21 ] = '\0' ;
F_10 ( V_1 -> V_22 , L_1 , V_1 -> V_4 ) ;
if ( ! memcmp ( V_1 -> V_4 , L_2 , 3 ) ||
! memcmp ( V_1 -> V_4 , L_3 , 3 ) ) {
F_1 ( V_1 ) ;
} else {
strcpy ( V_1 -> V_23 , V_1 -> V_4 ) ;
F_11 ( & V_1 -> V_24 ) ;
}
V_1 -> V_21 = 0 ;
V_1 -> V_20 = false ;
break;
case '\n' :
V_1 -> V_21 = 0 ;
V_1 -> V_20 = false ;
break;
case '?' :
V_1 -> V_21 = 0 ;
V_1 -> V_20 = true ;
break;
default:
if ( V_1 -> V_21 >= V_25 - 1 ) {
F_10 ( V_1 -> V_22 ,
L_4 , V_1 -> V_21 ) ;
V_1 -> V_21 = 0 ;
}
V_1 -> V_4 [ V_1 -> V_21 ++ ] = V_15 ;
break;
}
}
}
static T_1 F_12 ( struct V_26 * V_26 , unsigned char V_15 ,
unsigned int V_14 )
{
struct V_1 * V_1 = F_13 ( V_26 ) ;
if ( V_1 -> V_17 == V_25 ) {
F_14 ( V_1 -> V_22 , L_5 ) ;
return V_27 ;
}
F_15 ( & V_1 -> V_16 ) ;
V_1 -> V_17 ++ ;
V_1 -> V_18 [ V_1 -> V_28 ] = V_15 ;
V_1 -> V_28 = ( V_1 -> V_28 + 1 ) & 0xff ;
F_16 ( & V_1 -> V_16 ) ;
F_17 ( & V_1 -> V_13 ) ;
return V_27 ;
}
static void F_18 ( struct V_26 * V_26 )
{
struct V_1 * V_1 = F_13 ( V_26 ) ;
F_19 ( & V_1 -> V_13 ) ;
F_20 ( V_1 -> V_8 ) ;
F_21 ( & V_26 -> V_22 , L_6 ) ;
F_22 ( V_26 ) ;
F_23 ( V_26 , NULL ) ;
F_24 ( V_1 ) ;
}
static int F_25 ( struct V_1 * V_1 , const char * V_29 )
{
int V_30 = F_26 ( V_1 -> V_26 , '!' ) ;
F_10 ( V_1 -> V_22 , L_7 , V_29 ) ;
while ( ! V_30 && * V_29 )
V_30 = F_26 ( V_1 -> V_26 , * V_29 ++ ) ;
if ( ! V_30 )
V_30 = F_26 ( V_1 -> V_26 , '~' ) ;
return V_30 ;
}
static int F_27 ( struct V_1 * V_1 ,
const char * V_4 , const char * V_31 )
{
int V_30 ;
F_28 ( & V_1 -> V_24 ) ;
F_29 ( & V_1 -> V_32 ) ;
V_30 = F_25 ( V_1 , V_4 ) ;
if ( V_30 )
goto V_30;
if ( ! F_30 ( & V_1 -> V_24 , V_33 ) ) {
V_30 = - V_34 ;
goto V_30;
}
if ( V_31 && strncmp ( V_1 -> V_23 , V_31 , strlen ( V_31 ) ) ) {
F_10 ( V_1 -> V_22 ,
L_8 ,
V_4 , V_1 -> V_23 , V_31 ) ;
V_30 = - V_35 ;
}
V_30:
F_31 ( & V_1 -> V_32 ) ;
return V_30 ;
}
static int F_32 ( struct V_1 * V_1 , struct V_26 * V_26 ,
struct V_36 * V_37 , T_2 * V_38 )
{
int V_30 ;
V_30 = F_27 ( V_1 , L_9 , L_10 ) ;
if ( V_30 )
return V_30 ;
F_21 ( V_1 -> V_22 , L_11 , V_1 -> V_23 + 4 ) ;
V_30 = F_27 ( V_1 , L_12 , L_13 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_27 ( V_1 , L_14 , L_15 ) ;
if ( V_30 )
return V_30 ;
return F_27 ( V_1 , L_16 , L_17 ) ;
}
static int F_33 ( struct V_39 * V_8 , bool V_40 )
{
return 0 ;
}
static int F_34 ( struct V_39 * V_8 , T_3 V_41 )
{
struct V_1 * V_1 = F_35 ( V_8 ) ;
T_3 V_4 [ 16 ] ;
if ( V_41 == V_42 )
V_41 = V_43 ;
snprintf ( V_4 , sizeof( V_4 ) , L_18 , V_41 ) ;
return F_27 ( V_1 , V_4 , L_17 ) ;
}
static int F_36 ( struct V_39 * V_8 , T_3 V_44 ,
T_4 V_45 , struct V_2 * V_3 )
{
struct V_1 * V_1 = F_35 ( V_8 ) ;
char V_4 [ 2 * V_7 + 16 ] ;
unsigned int V_46 ;
int V_30 ;
if ( V_3 -> V_6 == 1 ) {
snprintf ( V_4 , sizeof( V_4 ) , L_19 , F_37 ( V_3 ) ) ;
} else {
char V_47 [ 3 ] ;
snprintf ( V_4 , sizeof( V_4 ) , L_20 ,
F_37 ( V_3 ) , V_3 -> V_3 [ 1 ] ) ;
for ( V_46 = 2 ; V_46 < V_3 -> V_6 ; V_46 ++ ) {
snprintf ( V_47 , sizeof( V_47 ) , L_21 , V_3 -> V_3 [ V_46 ] ) ;
F_38 ( V_4 , V_47 , sizeof( V_4 ) ) ;
}
}
F_29 ( & V_1 -> V_32 ) ;
V_30 = F_25 ( V_1 , V_4 ) ;
F_31 ( & V_1 -> V_32 ) ;
return V_30 ;
}
static int F_39 ( struct V_26 * V_26 , struct V_48 * V_49 )
{
T_4 V_50 = V_51 | V_52 | V_53 ;
struct V_1 * V_1 ;
int V_30 = - V_54 ;
struct V_36 V_37 = {} ;
T_2 V_38 = V_55 ;
V_1 = F_40 ( sizeof( * V_1 ) , V_56 ) ;
if ( ! V_1 )
return - V_54 ;
V_1 -> V_26 = V_26 ;
V_1 -> V_8 = F_41 ( & V_57 , V_1 ,
F_42 ( & V_26 -> V_22 ) , V_50 , 1 ) ;
V_30 = F_43 ( V_1 -> V_8 ) ;
if ( V_30 < 0 )
goto V_58;
V_1 -> V_22 = & V_26 -> V_22 ;
F_23 ( V_26 , V_1 ) ;
F_44 ( & V_1 -> V_13 , F_6 ) ;
F_45 ( & V_1 -> V_32 ) ;
F_46 ( & V_1 -> V_16 ) ;
V_30 = F_47 ( V_26 , V_49 ) ;
if ( V_30 )
goto V_59;
V_30 = F_32 ( V_1 , V_26 , & V_37 , & V_38 ) ;
if ( V_30 )
goto V_60;
V_30 = F_48 ( V_1 -> V_8 , & V_26 -> V_22 ) ;
if ( V_30 < 0 )
goto V_60;
V_1 -> V_22 = & V_1 -> V_8 -> V_61 . V_22 ;
return 0 ;
V_60:
F_22 ( V_26 ) ;
V_59:
F_49 ( V_1 -> V_8 ) ;
F_23 ( V_26 , NULL ) ;
V_58:
F_24 ( V_1 ) ;
return V_30 ;
}
