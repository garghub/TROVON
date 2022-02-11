static T_1
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 ;
char * V_9 = V_5 ;
* V_5 = 0 ;
for ( V_8 = 0 ; V_8 < V_7 -> V_10 ; V_8 ++ )
V_9 += sprintf ( V_9 , L_1 ,
V_7 -> args [ V_8 ] . V_11 ,
V_7 -> args [ V_8 ] . V_12 ? L_2 : L_3 ,
V_7 -> args [ V_8 ] . V_12 ? V_7 -> args [ V_8 ] . V_12 : L_3 ,
V_7 -> args [ V_8 ] . V_12 ? L_4 : L_3 ,
V_7 -> args [ V_8 ] . V_13 ) ;
return V_9 - V_5 ;
}
static void
F_3 ( struct V_1 * V_2 )
{
struct V_14 * V_15 =
F_4 ( V_2 , struct V_14 , V_2 ) ;
F_5 ( & V_15 -> V_16 ) ;
F_6 ( V_15 ) ;
}
int F_7 ( struct V_6 * V_7 )
{
struct V_14 * V_15 ;
int V_17 , V_8 ;
if ( ! V_7 )
return - V_18 ;
V_15 = F_8 ( sizeof( struct V_14 ) , V_19 ) ;
if ( ! V_15 )
return - V_20 ;
V_15 -> V_7 = V_7 ;
V_15 -> V_2 . V_21 = V_22 ;
V_15 -> V_2 . V_23 = F_3 ;
F_9 ( & V_15 -> V_2 , V_7 ) ;
F_10 ( & V_15 -> V_2 , L_5 , V_7 -> V_11 ) ;
V_17 = F_11 ( & V_15 -> V_2 ) ;
if ( V_17 ) {
F_12 ( V_24 L_6 ,
V_25 , V_7 -> V_11 ) ;
goto V_26;
}
F_13 ( & V_15 -> V_16 , & V_27 ) ;
for ( V_8 = 0 ; V_8 < F_14 ( V_28 ) ; ++ V_8 ) {
V_17 = F_15 ( & V_15 -> V_2 ,
& V_28 [ V_8 ] ) ;
if ( V_17 ) {
F_12 ( V_24 L_7 ,
V_25 ) ;
goto V_29;
}
}
#ifdef F_16
F_12 ( V_30 L_8 , V_25 , V_7 -> V_11 ) ;
#endif
return 0 ;
V_29:
F_17 ( & V_15 -> V_2 ) ;
return V_17 ;
V_26:
F_6 ( V_15 ) ;
return V_17 ;
}
void F_18 ( struct V_6 * V_7 )
{
struct V_14 * V_15 , * V_31 ;
if ( ! V_7 )
return;
F_19 (entry, n, &dsp_elements, list)
if ( V_15 -> V_7 == V_7 ) {
F_17 ( & V_15 -> V_2 ) ;
#ifdef F_16
F_12 ( V_30 L_9 ,
V_25 , V_7 -> V_11 ) ;
#endif
return;
}
F_12 ( V_24 L_10 , V_25 , V_7 -> V_11 ) ;
}
int F_20 ( void )
{
V_22 = F_21 ( V_32 , L_11 ) ;
if ( F_22 ( V_22 ) )
return F_23 ( V_22 ) ;
#ifdef F_16
F_12 ( V_30 L_12 , V_25 ) ;
#endif
F_24 () ;
return 0 ;
}
void F_25 ( void )
{
struct V_14 * V_15 , * V_31 ;
F_26 () ;
F_27 ( V_22 ) ;
F_19 (entry, n, &dsp_elements, list) {
F_5 ( & V_15 -> V_16 ) ;
F_12 ( V_33 L_13 ,
V_25 , V_15 -> V_7 -> V_11 ) ;
F_6 ( V_15 ) ;
}
#ifdef F_16
F_12 ( V_30 L_14 , V_25 ) ;
#endif
}
int F_28 ( struct V_34 * V_35 )
{
if ( ! V_35 )
return - V_18 ;
F_29 ( & V_35 -> V_16 ) ;
#ifdef F_16
F_12 ( V_30 L_15 , V_25 ) ;
#endif
return 0 ;
}
static inline void F_30 ( struct V_34 * V_35 )
{
struct V_36 * V_15 , * V_31 ;
F_19 (entry, n, &pipeline->list, list) {
F_5 ( & V_15 -> V_16 ) ;
if ( V_15 -> V_7 == V_37 )
F_31 ( F_4 ( V_35 , struct V_38 ,
V_35 ) ) ;
else
V_15 -> V_7 -> free ( V_15 -> V_9 ) ;
F_6 ( V_15 ) ;
}
}
void F_32 ( struct V_34 * V_35 )
{
if ( ! V_35 )
return;
F_30 ( V_35 ) ;
#ifdef F_16
F_12 ( V_30 L_16 , V_25 ) ;
#endif
}
int F_33 ( struct V_34 * V_35 , const char * V_39 )
{
int V_40 = 0 , V_41 = 0 ;
char * V_42 , * V_43 , * V_11 , * args ;
struct V_14 * V_15 , * V_31 ;
struct V_36 * V_44 ;
struct V_6 * V_7 ;
if ( ! V_35 )
return - V_18 ;
if ( ! F_34 ( & V_35 -> V_16 ) )
F_30 ( V_35 ) ;
V_42 = F_35 ( V_39 , V_19 ) ;
if ( ! V_42 )
return 0 ;
while ( ( V_43 = F_36 ( & V_42 , L_17 ) ) ) {
if ( ! strlen ( V_43 ) )
continue;
V_11 = F_36 ( & V_43 , L_18 ) ;
args = F_36 ( & V_43 , L_19 ) ;
if ( args && ! * args )
args = NULL ;
F_19 (entry, n, &dsp_elements, list)
if ( ! strcmp ( V_15 -> V_7 -> V_11 , V_11 ) ) {
V_7 = V_15 -> V_7 ;
V_44 = F_37 ( sizeof( struct
V_36 ) , V_19 ) ;
if ( ! V_44 ) {
F_12 ( V_24 L_20
L_21
L_22 , V_25 , V_7 -> V_11 ) ;
V_40 = 1 ;
goto V_45;
}
V_44 -> V_7 = V_7 ;
if ( V_7 == V_37 ) {
F_38 ( F_4 ( V_35 ,
struct V_38 , V_35 ) , args ) ;
F_13 ( & V_44 -> V_16 ,
& V_35 -> V_16 ) ;
} else {
V_44 -> V_9 = V_7 -> V_46 ( args ) ;
if ( V_44 -> V_9 ) {
F_13 ( & V_44 ->
V_16 , & V_35 -> V_16 ) ;
#ifdef F_16
F_12 ( V_30 L_23
L_24 ,
V_25 , V_11 , args ?
L_25 : L_3 , args ?
args : L_3 ) ;
#endif
} else {
F_12 ( V_24 L_26
L_27
L_28 ,
V_25 , V_7 -> V_11 ) ;
F_6 ( V_44 ) ;
V_40 = 1 ;
}
}
V_41 = 1 ;
break;
}
if ( V_41 )
V_41 = 0 ;
else {
F_12 ( V_24 L_29
L_30 , V_25 , V_11 ) ;
V_40 = 1 ;
}
}
V_45:
if ( ! F_34 ( & V_35 -> V_16 ) )
V_35 -> V_47 = 1 ;
else
V_35 -> V_47 = 0 ;
#ifdef F_16
F_12 ( V_30 L_31 ,
V_25 , V_40 ? L_32 : L_3 , V_39 ) ;
#endif
F_6 ( V_42 ) ;
return 0 ;
}
void F_39 ( struct V_34 * V_35 , T_2 * V_48 , int V_49 )
{
struct V_36 * V_15 ;
if ( ! V_35 )
return;
F_40 (entry, &pipeline->list, list)
if ( V_15 -> V_7 -> V_50 )
V_15 -> V_7 -> V_50 ( V_15 -> V_9 , V_48 , V_49 ) ;
}
void F_41 ( struct V_34 * V_35 , T_2 * V_48 , int V_49 ,
unsigned int V_51 )
{
struct V_36 * V_15 ;
if ( ! V_35 )
return;
F_42 (entry, &pipeline->list, list)
if ( V_15 -> V_7 -> V_52 )
V_15 -> V_7 -> V_52 ( V_15 -> V_9 , V_48 , V_49 , V_51 ) ;
}
