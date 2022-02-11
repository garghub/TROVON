static int F_1 ( int V_1 , int V_2 )
{
int V_3 ;
V_3 = F_2 ( V_1 , V_4 , 0 ) ;
if ( V_3 < 0 ) {
perror ( L_1 ) ;
return V_3 ;
}
V_2 |= V_3 ;
V_3 = F_2 ( V_1 , V_5 , V_2 ) ;
if ( V_3 < 0 ) {
perror ( L_2 ) ;
return V_3 ;
}
return V_3 ;
}
static int F_3 ( int V_1 , int V_6 , T_1 * V_7 )
{
if ( V_1 > V_6 )
V_6 = V_1 ;
F_4 ( V_1 , V_7 ) ;
return V_6 ;
}
static int F_5 ( int V_1 , struct V_8 * V_9 )
{
char * V_10 ;
int V_11 ;
V_10 = & V_9 -> V_12 [ V_9 -> V_13 ] ;
V_11 = F_6 ( V_9 ) ;
V_11 = F_7 ( V_1 , V_10 , V_11 ) ;
if ( V_11 < 0 )
perror ( L_3 ) ;
else if ( V_11 > 0 )
V_9 -> V_13 = ( V_9 -> V_13 + V_11 ) & ( V_14 - 1 ) ;
return V_11 ;
}
static int F_8 ( int V_15 , struct V_8 * V_9 )
{
char * V_10 ;
int V_11 ;
int V_16 = strlen ( V_17 ) ;
V_10 = & V_9 -> V_12 [ V_9 -> V_13 ] ;
V_11 = F_6 ( V_9 ) ;
if ( V_11 > V_16 ) {
memcpy ( V_10 , V_17 , V_16 ) ;
V_17 += V_16 ;
V_11 = V_16 ;
} else {
memcpy ( V_10 , V_17 , V_11 ) ;
V_17 += V_11 ;
}
if ( V_11 > 0 )
V_9 -> V_13 = ( V_9 -> V_13 + V_11 ) & ( V_14 - 1 ) ;
return V_11 ;
}
static int F_9 ( int V_1 , struct V_8 * V_9 )
{
char * V_10 ;
int V_11 ;
int V_3 = 0 ;
V_10 = & V_9 -> V_12 [ V_9 -> V_13 ] ;
V_11 = F_6 ( V_9 ) ;
while ( V_3 < V_11 && V_18 != V_19 ) {
if ( V_18 == V_20 ) {
* V_10 = V_21 ;
V_11 = 1 ;
V_9 -> V_13 = ( V_9 -> V_13 + 1 ) & ( V_14 - 1 ) ;
V_3 += 1 ;
V_18 = V_22 ;
} else {
V_11 = F_7 ( V_1 , V_10 , 1 ) ;
if ( V_11 <= 0 ) {
if ( V_11 < 0 )
perror ( L_3 ) ;
V_3 = V_11 ;
break;
}
}
switch ( V_18 ) {
case V_22 :
if ( * V_10 == '\n' )
V_18 = V_23 ;
V_9 -> V_13 = ( V_9 -> V_13 + 1 ) & ( V_14 - 1 ) ;
V_3 += 1 ;
break;
case V_23 :
if ( * V_10 == V_24 ||
* V_10 == V_25 ) {
V_26 = * V_10 ;
V_18 = V_27 ;
} else {
if ( * V_10 != '\n' )
V_18 = V_22 ;
V_9 -> V_13 = ( V_9 -> V_13 + 1 ) & ( V_14 - 1 ) ;
V_3 += 1 ;
}
break;
case V_27 :
if ( * V_10 == ' ' ) {
V_18 = V_19 ;
V_28 = true ;
} else {
V_18 = V_20 ;
V_21 = * V_10 ;
* V_10 = V_26 ;
V_9 -> V_13 = ( V_9 -> V_13 + 1 ) & ( V_14 - 1 ) ;
V_3 += 1 ;
}
break;
default:
assert ( 0 ) ;
break;
}
}
return V_3 ;
}
static int F_10 ( int V_1 , struct V_8 * V_9 )
{
char * V_10 ;
int V_11 ;
V_10 = & V_9 -> V_12 [ V_9 -> V_29 ] ;
V_11 = F_11 ( V_9 ) ;
V_11 = F_12 ( V_1 , V_10 , V_11 ) ;
if ( V_11 < 0 )
perror ( L_4 ) ;
else if ( V_11 > 0 )
V_9 -> V_29 = ( V_9 -> V_29 + V_11 ) & ( V_14 - 1 ) ;
return V_11 ;
}
static int F_13 ( int V_1 , struct V_8 * V_9 )
{
char * V_10 ;
int V_11 ;
V_10 = & V_9 -> V_12 [ V_9 -> V_29 ] ;
V_11 = F_11 ( V_9 ) ;
if ( ! V_30 ) {
V_11 = F_12 ( V_1 , V_10 , V_11 ) ;
if ( V_11 < 0 )
perror ( L_4 ) ;
}
if ( V_11 > 0 )
V_9 -> V_29 = ( V_9 -> V_29 + V_11 ) & ( V_14 - 1 ) ;
return V_11 ;
}
static int F_14 ( int V_1 , struct V_8 * V_9 )
{
int V_11 ;
V_11 = F_10 ( V_1 , V_9 ) ;
if ( F_11 ( V_9 ) == 0 )
V_31 = V_32 ;
return V_11 ;
}
static void F_15 ( int V_1 )
{
T_1 V_33 ;
T_1 V_34 ;
struct V_35 V_36 ;
int V_3 ;
int V_6 = 0 ;
if ( V_37 == V_38 ) {
V_18 = V_22 ;
V_17 = V_39 ;
if ( V_30 )
V_31 = V_32 ;
else
V_31 = V_40 ;
}
V_28 = false ;
while ( ! V_28 ) {
V_36 . V_41 = V_42 ;
V_36 . V_43 = 0 ;
F_16 ( & V_33 ) ;
F_16 ( & V_34 ) ;
if ( F_17 () ) {
if ( V_37 == V_44 )
V_6 = F_3 ( V_45 , V_6 , & V_33 ) ;
else if ( strlen ( V_17 ) &&
V_31 == V_40 )
F_18 ( V_45 , F_7 , V_46 , V_3 ) ;
}
if ( F_19 () &&
( V_37 == V_44 ||
V_31 == V_40 ) )
V_6 = F_3 ( V_1 , V_6 , & V_34 ) ;
if ( F_20 () &&
( V_37 == V_44 ||
V_31 == V_32 ) )
V_6 = F_3 ( V_1 , V_6 , & V_33 ) ;
if ( F_21 () )
V_6 = F_3 ( V_47 , V_6 , & V_34 ) ;
V_3 = F_22 ( V_6 + 1 , & V_33 , & V_34 , NULL , & V_36 ) ;
if ( V_3 < 0 ) {
perror ( L_5 ) ;
break;
}
if ( V_3 > 0 ) {
if ( F_23 ( V_45 , & V_33 ) )
F_24 ( V_45 , F_7 , V_46 , V_3 ) ;
if ( F_23 ( V_1 , & V_34 ) ) {
if ( V_37 == V_38 )
F_18 ( V_1 , F_12 , V_46 , V_3 ) ;
else
F_24 ( V_1 , F_12 , V_46 , V_3 ) ;
}
if ( F_23 ( V_1 , & V_33 ) ) {
if ( V_37 == V_38 )
F_18 ( V_1 , F_7 , log , V_3 ) ;
else
F_24 ( V_1 , F_7 , log , V_3 ) ;
}
if ( F_23 ( V_47 , & V_34 ) ) {
if ( V_37 == V_38 )
F_18 ( V_47 , F_12 , log , V_3 ) ;
else
F_24 ( V_47 , F_12 , log , V_3 ) ;
}
}
}
}
static bool F_25 ( int V_1 )
{
T_1 V_33 ;
struct V_35 V_36 ;
int V_3 ;
int V_6 = 0 ;
V_36 . V_41 = 0 ;
V_36 . V_43 = V_48 ;
F_16 ( & V_33 ) ;
V_6 = F_3 ( V_1 , V_6 , & V_33 ) ;
V_3 = F_22 ( V_6 + 1 , & V_33 , NULL , NULL , & V_36 ) ;
if ( V_3 < 0 )
perror ( L_5 ) ;
if ( V_3 > 0 && F_23 ( V_1 , & V_33 ) )
return true ;
return false ;
}
static void F_26 ( int V_1 )
{
while ( F_25 ( V_1 ) ) {
V_30 = true ;
F_15 ( V_1 ) ;
V_30 = false ;
}
}
void F_27 ( T_2 * V_49 , char * V_50 )
{
fprintf ( V_49 , L_6 , V_50 ) ;
fprintf ( V_49 , L_7 ) ;
fprintf ( V_49 , L_8 ) ;
fprintf ( V_49 , L_9 ) ;
fprintf ( V_49 , L_10 ) ;
fprintf ( V_49 , L_11 ) ;
}
int main ( int V_51 , char * * V_52 )
{
int V_1 = - 1 ;
int V_53 ;
int V_11 ;
int V_3 = V_54 ;
while ( ( V_53 = F_28 ( V_51 , V_52 , L_12 ) ) != - 1 ) {
switch ( V_53 ) {
case 'b' :
if ( V_39 ) {
fprintf ( V_55 , L_13 ,
V_39 ) ;
V_3 = V_56 ;
goto exit;
}
V_11 = strlen ( V_57 ) ;
V_39 = calloc ( V_11 + 2 , 1 ) ;
if ( ! V_39 ) {
perror ( L_14 ) ;
V_3 = V_56 ;
goto exit;
}
memcpy ( V_39 , V_57 , V_11 ) ;
V_39 [ V_11 ] = '\n' ;
V_37 = V_38 ;
break;
case 'f' :
V_58 = V_57 ;
break;
case 'h' :
F_27 ( stdout , V_52 [ 0 ] ) ;
goto exit;
break;
case '?' :
default:
F_27 ( V_55 , V_52 [ 0 ] ) ;
V_3 = V_56 ;
goto exit;
break;
}
}
V_1 = F_29 ( V_58 , V_59 | V_60 ) ;
if ( V_1 < 0 ) {
perror ( L_15 ) ;
V_3 = V_56 ;
goto exit;
}
F_1 ( V_45 , V_60 ) ;
F_1 ( V_47 , V_60 ) ;
if ( V_37 == V_38 )
F_26 ( V_1 ) ;
F_15 ( V_1 ) ;
exit:
if ( V_1 >= 0 )
F_30 ( V_1 ) ;
if ( V_39 )
free ( V_39 ) ;
return V_3 ;
}
