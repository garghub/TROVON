static enum V_1 F_1 ( const char * V_2 , int V_3 )
{
struct V_4 {
const char * V_5 ;
enum V_1 V_2 ;
};
static const struct V_4 V_6 [ 7 ] = {
{ . V_5 = L_1 ,
. V_2 = V_7 } ,
{ . V_5 = L_2 ,
. V_2 = V_8 } ,
{ . V_5 = L_3 ,
. V_2 = V_9 } ,
{ . V_5 = L_4 ,
. V_2 = V_10 } ,
{ . V_5 = L_5 ,
. V_2 = V_11 } ,
{ . V_5 = L_6 ,
. V_2 = V_12 } ,
{ . V_5 = NULL }
} ;
const struct V_4 * V_13 ;
T_1 V_14 = 0xffffU ;
if ( V_3 == 0 )
return V_15 ;
V_14 = F_2 ( V_14 , V_2 , V_3 ) ;
V_13 = V_6 + ( V_14 % F_3 ( V_6 ) ) ;
F_4 ( L_7 ,
V_2 , V_14 , ( V_14 % F_3 ( V_6 ) ) ) ;
if ( ! V_13 -> V_5 || strncmp ( V_13 -> V_5 , V_2 , V_3 ) )
return V_15 ;
F_4 ( L_8 ,
V_13 -> V_5 , V_13 -> V_2 ) ;
return V_13 -> V_2 ;
}
static int F_5 ( char * V_2 , struct V_16 * V_17 )
{
char * V_18 ;
int V_19 = 0 ;
V_17 -> V_20 = V_15 ;
V_17 -> V_21 = NULL ;
while ( * V_2 != '\0' ) {
while ( isspace ( * V_2 ) )
++ V_2 ;
if ( * V_2 == '\0' )
break;
V_18 = V_2 ;
switch ( V_19 ) {
case 0 :
while ( ( * V_2 != '\0' ) && ! isspace ( * V_2 ) )
++ V_2 ;
V_17 -> V_20 = F_1 ( V_18 , V_2 - V_18 ) ;
break;
case 1 :
while ( ( * V_2 != '\0' ) && ! iscntrl ( * V_2 ) )
++ V_2 ;
V_17 -> V_21 = V_18 ;
default:
* V_2 = '\0' ;
break;
}
++ V_19 ;
}
if ( ! V_17 -> V_21 || ( V_17 -> V_20 == V_15 ) )
return - V_22 ;
return 0 ;
}
T_2 F_6 ( const struct V_16 * V_17 )
{
T_2 V_3 ;
F_7 ( & V_23 ) ;
if ( V_24 && V_25 ) {
F_4 ( L_9 ,
V_17 -> V_20 , V_17 -> V_21 , ( long long ) V_17 -> V_26 , V_17 -> V_3 ) ;
V_3 = F_8 ( V_17 , V_24 -> V_27 ) ;
} else {
V_3 = - V_28 ;
}
F_9 ( & V_23 ) ;
return V_3 ;
}
int F_10 ( void )
{
int V_29 ;
struct V_16 V_17 = {
. V_20 = V_15 ,
. V_26 = 0 ,
. V_21 = L_10 ,
. V_3 = V_30
} ;
V_17 . V_31 = ( void * ) F_11 ( V_32 | V_33 ) ;
if ( ! V_17 . V_31 )
return - V_34 ;
V_29 = F_12 () ;
if ( V_29 )
return V_29 ;
V_29 = F_6 ( & V_17 ) ;
F_13 ( ( unsigned long ) V_17 . V_31 ) ;
F_14 () ;
switch ( V_29 ) {
case - V_35 :
case - V_36 :
V_29 = 0 ;
break;
default:
if ( V_29 > 0 )
V_29 = 0 ;
break;
}
return V_29 ;
}
T_2 F_15 ( char T_3 * V_2 , T_4 V_37 ,
char T_5 * V_31 , T_6 V_3 )
{
int V_38 ;
struct V_16 V_17 = { . V_3 = V_3 , . V_26 = V_37 } ;
T_2 V_39 = F_5 ( V_2 , & V_17 ) ;
if ( V_39 )
return V_39 ;
V_38 = F_16 ( V_17 . V_3 ) ;
V_17 . V_31 = ( void * ) F_17 ( V_32 | V_33 , V_38 ) ;
if ( ! V_17 . V_31 )
return - V_34 ;
switch ( V_17 . V_20 ) {
case V_8 :
case V_10 :
case V_7 :
V_39 = F_6 ( & V_17 ) ;
if ( ( V_39 >= 0 ) &&
F_18 ( V_31 , V_17 . V_31 , V_39 ) )
V_39 = - V_40 ;
break;
case V_11 :
case V_12 :
if ( ! F_19 ( V_17 . V_31 , V_31 , V_17 . V_3 ) )
V_39 = F_6 ( & V_17 ) ;
else
V_39 = - V_40 ;
break;
case V_9 :
V_39 = F_6 ( & V_17 ) ;
break;
default:
V_39 = - V_41 ;
break;
}
F_20 ( ( unsigned long ) V_17 . V_31 , V_38 ) ;
return V_39 ;
}
int F_12 ( void )
{
static struct V_42 V_43 = {
. V_44 = V_45 ,
. V_46 = V_47 ,
. V_27 = V_48
} ;
static struct V_42 V_49 = {
. V_44 = V_50 ,
. V_46 = V_51 ,
. V_27 = V_52
} ;
int V_29 = 0 ;
F_7 ( & V_23 ) ;
if ( V_25 == 0 ) {
if ( V_53 )
V_24 = & V_43 ;
else if ( V_54 || V_55 )
V_24 = & V_49 ;
else
V_29 = - V_41 ;
if ( V_24 )
V_29 = V_24 -> V_44 () ;
}
if ( ! V_29 )
++ V_25 ;
F_9 ( & V_23 ) ;
return V_29 ;
}
void F_14 ( void )
{
F_7 ( & V_23 ) ;
-- V_25 ;
if ( ( V_25 == 0 ) && V_24 )
V_24 -> V_46 () ;
F_9 ( & V_23 ) ;
}
