int F_1 ( struct V_1 * V_2 )
{
static char * V_3 [ V_4 ] [ 4 ] = {
[ V_5 ] = {
NULL , L_1 , L_2 , L_3 ,
} ,
[ V_6 ] = {
NULL , L_4 , L_5 , L_6 ,
} ,
[ V_7 ] = {
NULL , L_4 , L_5 , L_6 ,
} ,
[ V_8 ] = {
L_7 , L_8 , L_9 , L_10
} ,
[ V_9 ] = {
L_11 , L_12 , L_9 , L_13
} ,
} ;
int V_10 , V_11 ;
for ( V_10 = 0 ; V_10 < 4 ; V_10 ++ ) {
char V_12 [ 32 ] ;
const struct V_13 * V_14 ;
if ( ! V_3 [ V_2 -> type ] [ V_10 ] )
continue;
sprintf ( V_12 , L_14 , V_3 [ V_2 -> type ] [ V_10 ] ) ;
if ( F_2 ( & V_14 , V_12 , V_2 -> V_15 ) ) {
F_3 ( V_16 L_15 , V_12 ) ;
return - V_17 ;
}
V_11 = V_2 -> V_18 -> V_19 ( V_2 , V_10 , V_14 ) ;
if ( V_11 < 0 ) {
F_4 ( V_14 ) ;
return V_11 ;
}
if ( V_10 == 1 )
V_2 -> V_20 |= V_21 ;
#ifdef F_5
V_2 -> V_13 [ V_10 ] = V_14 ;
#else
F_4 ( V_14 ) ;
#endif
}
if ( ( V_11 = F_6 ( V_2 ) ) < 0 )
return V_11 ;
if ( ( V_11 = F_7 ( V_2 ) ) < 0 )
return V_11 ;
if ( V_2 -> V_18 -> V_22 )
if ( ( V_11 = V_2 -> V_18 -> V_22 ( V_2 ) ) < 0 )
return V_11 ;
V_2 -> V_20 |= V_23 ;
V_2 -> V_20 |= V_24 ;
return F_8 ( V_2 -> V_25 ) ;
}
void F_9 ( struct V_1 * V_2 )
{
#ifdef F_5
int V_10 ;
for ( V_10 = 0 ; V_10 < 4 ; V_10 ++ )
F_4 ( V_2 -> V_13 [ V_10 ] ) ;
#endif
}
static int F_10 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
static char * V_30 [ V_4 ] = {
[ V_5 ] = L_16 ,
[ V_6 ] = L_17 ,
[ V_7 ] = L_17 ,
[ V_8 ] = L_18 ,
[ V_9 ] = L_19 ,
} ;
struct V_1 * V_31 = V_27 -> V_32 ;
if ( F_11 ( ! V_30 [ V_31 -> type ] ) )
return - V_33 ;
strcpy ( V_29 -> V_34 , V_30 [ V_31 -> type ] ) ;
if ( F_12 ( V_31 ) )
V_29 -> V_35 = 4 ;
else
V_29 -> V_35 = 3 ;
if ( V_31 -> V_20 & V_24 )
V_29 -> V_36 = 1 ;
V_29 -> V_37 = V_38 ;
return 0 ;
}
static void F_13 ( const struct V_13 * V_14 )
{
if ( V_14 ) {
F_14 ( V_14 -> V_39 ) ;
F_15 ( V_14 ) ;
}
}
static int F_16 ( struct V_26 * V_27 ,
struct V_40 * V_41 )
{
struct V_1 * V_31 = V_27 -> V_32 ;
int V_42 , V_11 ;
struct V_13 * V_14 ;
if ( F_11 ( ! V_31 -> V_18 -> V_19 ) )
return - V_43 ;
V_14 = F_17 ( sizeof( * V_14 ) , V_44 ) ;
if ( ! V_14 ) {
F_3 ( V_16 L_20 ) ;
return - V_45 ;
}
V_14 -> V_46 = V_41 -> V_47 ;
V_14 -> V_39 = F_18 ( V_14 -> V_46 ) ;
if ( ! V_14 -> V_39 ) {
F_3 ( V_16 L_21 ,
( int ) V_14 -> V_46 ) ;
F_15 ( V_14 ) ;
return - V_45 ;
}
if ( F_19 ( ( void * ) V_14 -> V_39 , V_41 -> V_48 , V_41 -> V_47 ) ) {
F_13 ( V_14 ) ;
return - V_49 ;
}
V_42 = V_41 -> V_42 ;
if ( ! F_12 ( V_31 ) )
V_42 ++ ;
V_11 = V_31 -> V_18 -> V_19 ( V_31 , V_42 , V_14 ) ;
if ( V_11 < 0 ) {
F_13 ( V_14 ) ;
return V_11 ;
}
#ifdef F_5
V_31 -> V_13 [ V_42 ] = V_14 ;
#else
F_13 ( V_14 ) ;
#endif
if ( V_42 == 1 )
V_31 -> V_20 |= V_21 ;
if ( V_42 < 3 )
return 0 ;
if ( ! ( V_31 -> V_20 & V_23 ) ) {
if ( ( V_11 = F_6 ( V_31 ) ) < 0 )
return V_11 ;
if ( ( V_11 = F_7 ( V_31 ) ) < 0 )
return V_11 ;
if ( V_31 -> V_18 -> V_22 )
if ( ( V_11 = V_31 -> V_18 -> V_22 ( V_31 ) ) < 0 )
return V_11 ;
if ( ( V_11 = F_8 ( V_31 -> V_25 ) ) < 0 )
return V_11 ;
V_31 -> V_20 |= V_23 ;
}
V_31 -> V_20 |= V_24 ;
return 0 ;
}
int F_1 ( struct V_1 * V_2 )
{
int V_11 ;
struct V_26 * V_27 ;
if ( ( V_11 = F_20 ( V_2 -> V_25 , V_50 , 0 , & V_27 ) ) < 0 )
return V_11 ;
V_27 -> V_51 = V_52 ;
V_27 -> V_32 = V_2 ;
V_27 -> V_18 . V_53 = F_10 ;
V_27 -> V_18 . V_54 = F_16 ;
V_27 -> V_55 = 1 ;
sprintf ( V_27 -> V_56 , L_22 , V_2 -> V_25 -> V_57 ) ;
V_2 -> V_58 = V_27 ;
return F_8 ( V_2 -> V_25 ) ;
}
void F_9 ( struct V_1 * V_2 )
{
#ifdef F_5
int V_10 ;
for ( V_10 = 0 ; V_10 < 4 ; V_10 ++ )
F_13 ( V_2 -> V_13 [ V_10 ] ) ;
#endif
}
