static void F_1 ( struct V_1 * V_2 , struct V_3 * args )
{
T_1 V_4 , V_5 , V_6 ;
int V_7 ;
if ( F_2 ( args -> V_8 ) != 3 || F_2 ( args -> V_9 ) != 1 ) {
V_7 = - 3 ;
goto V_10;
}
V_4 = F_2 ( args -> args [ 0 ] ) ;
V_5 = F_2 ( args -> args [ 1 ] ) ;
V_6 = F_2 ( args -> args [ 2 ] ) ;
V_7 = F_3 ( V_2 -> V_11 , V_4 , V_5 , V_6 ) ;
if ( V_7 )
V_7 = - 3 ;
V_10:
args -> V_12 [ 0 ] = F_4 ( V_7 ) ;
}
static void F_5 ( struct V_1 * V_2 , struct V_3 * args )
{
T_1 V_4 , V_5 , V_6 ;
int V_7 ;
if ( F_2 ( args -> V_8 ) != 1 || F_2 ( args -> V_9 ) != 3 ) {
V_7 = - 3 ;
goto V_10;
}
V_4 = F_2 ( args -> args [ 0 ] ) ;
V_5 = V_6 = 0 ;
V_7 = F_6 ( V_2 -> V_11 , V_4 , & V_5 , & V_6 ) ;
if ( V_7 ) {
V_7 = - 3 ;
goto V_10;
}
args -> V_12 [ 1 ] = F_4 ( V_5 ) ;
args -> V_12 [ 2 ] = F_4 ( V_6 ) ;
V_10:
args -> V_12 [ 0 ] = F_4 ( V_7 ) ;
}
static void F_7 ( struct V_1 * V_2 , struct V_3 * args )
{
T_1 V_4 ;
int V_7 ;
if ( F_2 ( args -> V_8 ) != 1 || F_2 ( args -> V_9 ) != 1 ) {
V_7 = - 3 ;
goto V_10;
}
V_4 = F_2 ( args -> args [ 0 ] ) ;
V_7 = F_8 ( V_2 -> V_11 , V_4 ) ;
if ( V_7 )
V_7 = - 3 ;
V_10:
args -> V_12 [ 0 ] = F_4 ( V_7 ) ;
}
static void F_9 ( struct V_1 * V_2 , struct V_3 * args )
{
T_1 V_4 ;
int V_7 ;
if ( F_2 ( args -> V_8 ) != 1 || F_2 ( args -> V_9 ) != 1 ) {
V_7 = - 3 ;
goto V_10;
}
V_4 = F_2 ( args -> args [ 0 ] ) ;
V_7 = F_10 ( V_2 -> V_11 , V_4 ) ;
if ( V_7 )
V_7 = - 3 ;
V_10:
args -> V_12 [ 0 ] = F_4 ( V_7 ) ;
}
static int F_11 ( char * V_13 , char * V_14 )
{
struct V_15 args ;
return ! strncmp ( V_13 , V_14 , sizeof( args . V_16 ) ) ;
}
static int F_12 ( struct V_11 * V_11 , char * V_16 )
{
struct V_17 * V_18 , * V_19 ;
F_13 ( & V_11 -> V_20 ) ;
F_14 (d, tmp, &kvm->arch.rtas_tokens, list) {
if ( F_11 ( V_18 -> V_21 -> V_16 , V_16 ) ) {
F_15 ( & V_18 -> V_22 ) ;
F_16 ( V_18 ) ;
return 0 ;
}
}
return 0 ;
}
static int F_17 ( struct V_11 * V_11 , char * V_16 , T_2 V_23 )
{
struct V_17 * V_18 ;
struct V_24 * V_25 = NULL ;
bool V_26 ;
int V_27 ;
F_13 ( & V_11 -> V_20 ) ;
F_18 (d, &kvm->arch.rtas_tokens, list) {
if ( V_18 -> V_23 == V_23 )
return - V_28 ;
}
V_26 = false ;
for ( V_27 = 0 ; V_27 < F_19 ( V_29 ) ; V_27 ++ ) {
V_25 = & V_29 [ V_27 ] ;
if ( F_11 ( V_25 -> V_16 , V_16 ) ) {
V_26 = true ;
break;
}
}
if ( ! V_26 )
return - V_30 ;
V_18 = F_20 ( sizeof( * V_18 ) , V_31 ) ;
if ( ! V_18 )
return - V_32 ;
V_18 -> V_21 = V_25 ;
V_18 -> V_23 = V_23 ;
F_21 ( & V_18 -> V_22 , & V_11 -> V_33 . V_34 ) ;
return 0 ;
}
int F_22 ( struct V_11 * V_11 , void T_3 * V_35 )
{
struct V_15 args ;
int V_7 ;
if ( F_23 ( & args , V_35 , sizeof( args ) ) )
return - V_36 ;
F_24 ( & V_11 -> V_20 ) ;
if ( args . V_23 )
V_7 = F_17 ( V_11 , args . V_16 , args . V_23 ) ;
else
V_7 = F_12 ( V_11 , args . V_16 ) ;
F_25 ( & V_11 -> V_20 ) ;
return V_7 ;
}
int F_26 ( struct V_1 * V_2 )
{
struct V_17 * V_18 ;
struct V_3 args ;
T_4 * V_37 ;
T_5 V_38 ;
int V_7 ;
V_38 = F_27 ( V_2 , 4 ) & V_39 ;
V_7 = F_28 ( V_2 -> V_11 , V_38 , & args , sizeof( args ) ) ;
if ( V_7 )
goto V_40;
V_37 = args . V_12 ;
args . V_12 = & args . args [ F_2 ( args . V_8 ) ] ;
F_24 ( & V_2 -> V_11 -> V_20 ) ;
V_7 = - V_30 ;
F_18 (d, &vcpu->kvm->arch.rtas_tokens, list) {
if ( V_18 -> V_23 == F_2 ( args . V_23 ) ) {
V_18 -> V_21 -> V_21 ( V_2 , & args ) ;
V_7 = 0 ;
break;
}
}
F_25 ( & V_2 -> V_11 -> V_20 ) ;
if ( V_7 == 0 ) {
args . V_12 = V_37 ;
V_7 = F_29 ( V_2 -> V_11 , V_38 , & args , sizeof( args ) ) ;
if ( V_7 )
goto V_40;
}
return V_7 ;
V_40:
return V_7 ;
}
void F_30 ( struct V_11 * V_11 )
{
struct V_17 * V_18 , * V_19 ;
F_13 ( & V_11 -> V_20 ) ;
F_14 (d, tmp, &kvm->arch.rtas_tokens, list) {
F_15 ( & V_18 -> V_22 ) ;
F_16 ( V_18 ) ;
}
}
