struct V_1 * F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 = V_1 ;
int V_4 ;
F_2 ( & V_5 ) ;
for ( V_4 = 0 ; V_4 < V_6 ; V_4 ++ ) {
if ( V_7 [ V_4 ] == V_8 )
V_7 [ V_4 ] = V_2 -> V_9 ( V_10 ) ;
if ( V_11 [ V_4 ] == V_8 )
V_11 [ V_4 ] = V_2 -> V_12
( V_13 [ V_4 ] , V_10 ) ;
}
F_3 () ;
V_1 = V_2 ;
F_4 ( & V_5 ) ;
return V_3 ;
}
void F_5 ( struct V_14 * V_15 )
{
int V_4 ;
F_2 ( & V_5 ) ;
for ( V_4 = 0 ; V_4 < V_6 ; V_4 ++ ) {
if ( V_7 [ V_4 ] == V_16 ) {
V_15 -> V_17 = V_4 + V_18 ;
if ( V_1 )
V_7 [ V_4 ] = V_1 -> V_9 ( V_10 ) ;
else
V_7 [ V_4 ] = V_8 ;
break;
}
}
F_4 ( & V_5 ) ;
}
void F_6 ( char * V_19 , struct V_14 * V_15 )
{
int V_4 ;
F_2 ( & V_5 ) ;
for ( V_4 = 0 ; V_4 < V_6 ; V_4 ++ ) {
if ( V_11 [ V_4 ] == V_16 ) {
V_15 -> V_17 = V_4 + V_20 ;
V_13 [ V_4 ] = V_19 ;
if ( V_1 )
V_11 [ V_4 ] = V_1 -> V_12
( V_19 , V_10 ) ;
else
V_11 [ V_4 ] = V_8 ;
break;
}
}
F_4 ( & V_5 ) ;
}
static int F_7 ( struct V_21 * V_21 ,
struct V_22 * V_23 )
{
int (* F_8)( struct V_21 * , T_1 * V_24 , int * , struct V_21 * );
int V_25 = 0 , V_26 = V_27 ;
struct V_14 * V_15 = V_21 -> V_28 ;
V_23 -> V_29 . V_30 = V_21 -> V_31 ;
if ( V_15 -> V_32 != NULL ) {
F_8 = V_15 -> V_32 -> V_33 ;
if ( F_8 ) {
V_25 = (* F_8)( V_21 , & V_23 -> V_29 . V_24 [ 0 ] , & V_26 , NULL ) ;
if ( V_25 <= V_34 || V_25 == V_35 )
return - 1 ;
if ( V_26 > V_27 )
return - 1 ;
}
}
return 0 ;
}
static int F_9 ( int V_36 )
{
if ( V_36 >= V_20 )
return V_11 [ V_36 -
V_20 ] ;
else if ( V_36 >= V_18 )
return V_7 [ V_36 - V_18 ] ;
return V_8 ;
}
int F_10 ( struct V_37 * V_37 )
{
int V_38 = - 1 ;
int V_39 ;
int V_36 ;
struct V_22 V_23 = { . V_29 . V_23 = { 0 } } ;
if ( ! V_1 ) {
V_40 ++ ;
goto V_41;
}
F_11 ( ! F_12 ( V_37 ) , V_37 ) ;
V_36 = V_37 -> V_42 -> V_43 -> V_28 -> V_17 ;
if ( V_36 < 0 )
goto V_41;
V_39 = F_9 ( V_36 ) ;
if ( F_7 ( V_37 -> V_42 -> V_43 , & V_23 ) < 0 )
goto V_41;
if ( V_39 >= 0 )
V_38 = V_1 -> V_44 ( V_39 ,
V_23 , V_37 -> V_45 , V_37 ) ;
if ( V_38 == 0 )
V_46 ++ ;
else
V_40 ++ ;
V_41:
return V_38 ;
}
void F_13 ( struct V_37 * V_37 )
{
int V_39 ;
int V_36 ;
struct V_22 V_23 = { . V_29 . V_23 = { 0 } } ;
if ( ! V_1 ) {
V_47 ++ ;
return;
}
F_11 ( ! F_12 ( V_37 ) , V_37 ) ;
V_36 = V_37 -> V_42 -> V_43 -> V_28 -> V_17 ;
if ( V_36 < 0 )
return;
V_39 = F_9 ( V_36 ) ;
if ( V_39 >= 0 &&
F_7 ( V_37 -> V_42 -> V_43 , & V_23 ) >= 0 ) {
V_1 -> V_48 ( V_39 , V_23 , V_37 -> V_45 , V_37 ) ;
V_47 ++ ;
}
}
void F_14 ( struct V_49 * V_42 ,
struct V_37 * V_37 )
{
int V_39 ;
int V_36 = V_42 -> V_43 -> V_28 -> V_17 ;
struct V_22 V_23 = { . V_29 . V_23 = { 0 } } ;
if ( ! V_1 )
return;
if ( V_36 >= 0 ) {
V_39 = F_9 ( V_36 ) ;
if ( V_39 < 0 )
return;
F_11 ( ! F_12 ( V_37 ) , V_37 ) ;
if ( F_7 ( V_42 -> V_43 , & V_23 ) >= 0 ) {
V_1 -> V_50 ( V_39 ,
V_23 , V_37 -> V_45 ) ;
V_51 ++ ;
}
}
}
void F_15 ( struct V_49 * V_42 )
{
int V_39 ;
int V_36 = V_42 -> V_43 -> V_28 -> V_17 ;
struct V_22 V_23 = { . V_29 . V_23 = { 0 } } ;
if ( ! V_1 )
return;
if ( V_36 < 0 )
return;
V_39 = F_9 ( V_36 ) ;
if ( V_39 >= 0 && F_7 ( V_42 -> V_43 , & V_23 ) >= 0 )
V_1 -> V_52 ( V_39 , V_23 ) ;
}
void F_16 ( struct V_14 * V_15 )
{
int V_45 ;
int V_36 = V_15 -> V_17 ;
int V_53 = V_36 ;
F_2 ( & V_5 ) ;
if ( V_36 >= V_20 ) {
V_45 = V_36 - V_20 ;
V_53 = V_11 [ V_45 ] ;
V_11 [ V_45 ] = V_16 ;
V_13 [ V_45 ] = NULL ;
} else if ( V_36 >= V_18 ) {
V_45 = V_36 - V_18 ;
V_53 = V_7 [ V_45 ] ;
V_7 [ V_45 ] = V_16 ;
}
V_15 -> V_17 = - 1 ;
if ( V_1 )
V_1 -> V_54 ( V_53 ) ;
F_4 ( & V_5 ) ;
}
static int T_2 F_17 ( void )
{
int V_4 ;
#ifdef F_18
struct V_55 * V_56 = F_19 ( L_1 , NULL ) ;
if ( V_56 == NULL )
return - V_57 ;
F_20 ( L_2 , V_58 , V_56 , & V_46 ) ;
F_20 ( L_3 , V_58 ,
V_56 , & V_40 ) ;
F_20 ( L_4 , V_58 , V_56 , & V_47 ) ;
F_20 ( L_5 , V_58 ,
V_56 , & V_51 ) ;
#endif
for ( V_4 = 0 ; V_4 < V_6 ; V_4 ++ ) {
V_7 [ V_4 ] = V_16 ;
V_11 [ V_4 ] = V_16 ;
}
return 0 ;
}
