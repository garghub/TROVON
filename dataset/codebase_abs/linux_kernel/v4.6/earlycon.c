static void T_1 * T_2 F_1 ( unsigned long V_1 , T_3 V_2 )
{
void T_1 * V_3 ;
#ifdef F_2
F_3 ( V_4 , V_1 & V_5 ) ;
V_3 = ( void T_1 * ) F_4 ( V_4 ) ;
V_3 += V_1 & ~ V_5 ;
#else
V_3 = F_5 ( V_1 , V_2 ) ;
#endif
if ( ! V_3 )
F_6 ( L_1 , V_6 ,
( unsigned long long ) V_1 ) ;
return V_3 ;
}
static void T_2 F_7 ( struct V_7 * V_8 ,
const char * V_9 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_13 * V_14 = & V_8 -> V_14 ;
const char * V_15 ;
T_3 V_16 ;
for ( V_15 = V_9 + strlen ( V_9 ) ;
V_15 > V_9 && V_15 [ - 1 ] >= '0' && V_15 [ - 1 ] <= '9' ;
V_15 -- )
;
if ( * V_15 )
V_11 -> V_17 = F_8 ( V_15 , NULL , 10 ) ;
V_16 = V_15 - V_9 ;
F_9 ( V_11 -> V_9 , V_9 , F_10 ( V_16 + 1 , sizeof( V_11 -> V_9 ) ) ) ;
V_11 -> V_18 = & V_19 ;
if ( V_14 -> V_20 == V_21 || V_14 -> V_20 == V_22 ||
V_14 -> V_20 == V_23 || V_14 -> V_20 == V_24 )
F_11 ( L_2 ,
V_11 -> V_9 , V_11 -> V_17 ,
( V_14 -> V_20 == V_21 ) ? L_3 :
( V_14 -> V_20 == V_22 ) ? L_4 :
( V_14 -> V_20 == V_23 ) ? L_5 : L_6 ,
& V_14 -> V_25 , V_8 -> V_26 ) ;
else
F_11 ( L_7 ,
V_11 -> V_9 , V_11 -> V_17 ,
V_14 -> V_27 , V_8 -> V_26 ) ;
}
static int T_2 F_12 ( struct V_7 * V_8 , char * V_26 )
{
struct V_13 * V_14 = & V_8 -> V_14 ;
int V_28 ;
unsigned long V_29 ;
if ( F_13 ( V_26 , & V_14 -> V_20 , & V_29 , & V_26 ) )
return - V_30 ;
switch ( V_14 -> V_20 ) {
case V_21 :
V_14 -> V_25 = V_29 ;
break;
case V_22 :
V_14 -> V_31 = 1 ;
V_14 -> V_25 = V_29 ;
break;
case V_23 :
case V_24 :
V_14 -> V_31 = 2 ;
V_14 -> V_25 = V_29 ;
break;
case V_32 :
V_14 -> V_27 = V_29 ;
break;
default:
return - V_30 ;
}
if ( V_26 ) {
V_8 -> V_33 = F_8 ( V_26 , NULL , 0 ) ;
V_28 = F_10 ( strcspn ( V_26 , L_8 ) + 1 ,
( T_3 ) ( sizeof( V_8 -> V_26 ) ) ) ;
F_9 ( V_8 -> V_26 , V_26 , V_28 ) ;
}
return 0 ;
}
static int T_2 F_14 ( char * V_34 , const struct V_35 * V_36 )
{
int V_37 ;
struct V_13 * V_14 = & V_19 . V_14 ;
if ( V_34 && ! F_12 ( & V_19 , V_34 ) )
V_34 = NULL ;
F_15 ( & V_14 -> V_38 ) ;
V_14 -> V_39 = V_40 * 16 ;
if ( V_14 -> V_25 )
V_14 -> V_41 = F_1 ( V_14 -> V_25 , 64 ) ;
F_7 ( & V_19 , V_36 -> V_9 ) ;
V_37 = V_36 -> V_42 ( & V_19 , V_34 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( ! V_19 . V_12 -> V_43 )
return - V_44 ;
F_16 ( V_19 . V_12 ) ;
return 0 ;
}
int T_2 F_17 ( char * V_34 )
{
const struct V_35 * V_36 ;
if ( ! V_34 || ! V_34 [ 0 ] )
return - V_30 ;
if ( V_45 . V_46 & V_47 )
return - V_48 ;
for ( V_36 = V_49 ; V_36 < V_50 ; V_36 ++ ) {
T_3 V_16 = strlen ( V_36 -> V_9 ) ;
if ( strncmp ( V_34 , V_36 -> V_9 , V_16 ) )
continue;
if ( V_34 [ V_16 ] ) {
if ( V_34 [ V_16 ] != ',' )
continue;
V_34 += V_16 + 1 ;
} else
V_34 = NULL ;
return F_14 ( V_34 , V_36 ) ;
}
return - V_51 ;
}
static int T_2 F_18 ( char * V_34 )
{
int V_37 ;
if ( ! V_34 || ! V_34 [ 0 ] )
return 0 ;
V_37 = F_17 ( V_34 ) ;
if ( V_37 == - V_51 || V_37 == - V_48 )
return 0 ;
return V_37 ;
}
int T_2 F_19 ( const struct V_35 * V_36 ,
unsigned long V_52 ,
const char * V_26 )
{
int V_37 ;
struct V_13 * V_14 = & V_19 . V_14 ;
const T_4 * V_53 ;
bool V_54 ;
T_5 V_29 ;
F_15 ( & V_14 -> V_38 ) ;
V_14 -> V_20 = V_21 ;
V_29 = F_20 ( V_52 ) ;
if ( V_29 == V_55 ) {
F_21 ( L_9 , V_36 -> V_9 ) ;
return - V_56 ;
}
V_14 -> V_25 = V_29 ;
V_14 -> V_39 = V_40 * 16 ;
V_14 -> V_41 = F_1 ( V_14 -> V_25 , V_57 ) ;
V_53 = F_22 ( V_52 , L_10 , NULL ) ;
if ( V_53 )
V_14 -> V_25 += F_23 ( * V_53 ) ;
V_53 = F_22 ( V_52 , L_11 , NULL ) ;
if ( V_53 )
V_14 -> V_31 = F_23 ( * V_53 ) ;
V_54 = F_22 ( V_52 , L_12 , NULL ) != NULL ||
( F_24 ( V_58 ) &&
F_22 ( V_52 , L_13 , NULL ) != NULL ) ;
V_53 = F_22 ( V_52 , L_14 , NULL ) ;
if ( V_53 ) {
switch ( F_23 ( * V_53 ) ) {
case 1 :
V_14 -> V_20 = V_21 ;
break;
case 2 :
V_14 -> V_20 = V_22 ;
break;
case 4 :
V_14 -> V_20 = ( V_54 ) ? V_24 : V_23 ;
break;
default:
F_21 ( L_15 , V_36 -> V_9 ) ;
return - V_30 ;
}
}
if ( V_26 ) {
F_9 ( V_19 . V_26 , V_26 ,
sizeof( V_19 . V_26 ) ) ;
}
F_7 ( & V_19 , V_36 -> V_9 ) ;
V_37 = V_36 -> V_42 ( & V_19 , V_26 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( ! V_19 . V_12 -> V_43 )
return - V_44 ;
F_16 ( V_19 . V_12 ) ;
return 0 ;
}
