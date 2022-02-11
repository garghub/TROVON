bool F_1 ( unsigned int V_1 , T_1 * V_2 )
{
unsigned int V_3 , V_4 = F_2 ( & V_2 -> V_5 ) ;
do {
if ( ! V_4 )
return false ;
if ( F_3 ( V_4 == V_6 ) )
return true ;
V_3 = V_4 + V_1 ;
if ( V_3 < V_4 )
V_3 = V_6 ;
} while ( ! F_4 ( & V_2 -> V_5 , & V_4 , V_3 ) );
F_5 ( V_3 == V_6 , L_1 ) ;
return true ;
}
void F_6 ( unsigned int V_1 , T_1 * V_2 )
{
F_5 ( ! F_1 ( V_1 , V_2 ) , L_2 ) ;
}
bool F_7 ( T_1 * V_2 )
{
unsigned int V_3 , V_4 = F_2 ( & V_2 -> V_5 ) ;
do {
V_3 = V_4 + 1 ;
if ( ! V_4 )
return false ;
if ( F_3 ( ! V_3 ) )
return true ;
} while ( ! F_4 ( & V_2 -> V_5 , & V_4 , V_3 ) );
F_5 ( V_3 == V_6 , L_1 ) ;
return true ;
}
void F_8 ( T_1 * V_2 )
{
F_5 ( ! F_7 ( V_2 ) , L_3 ) ;
}
bool F_9 ( unsigned int V_1 , T_1 * V_2 )
{
unsigned int V_3 , V_4 = F_2 ( & V_2 -> V_5 ) ;
do {
if ( F_3 ( V_4 == V_6 ) )
return false ;
V_3 = V_4 - V_1 ;
if ( V_3 > V_4 ) {
F_5 ( V_3 > V_4 , L_4 ) ;
return false ;
}
} while ( ! F_10 ( & V_2 -> V_5 , & V_4 , V_3 ) );
return ! V_3 ;
}
bool F_11 ( T_1 * V_2 )
{
return F_9 ( 1 , V_2 ) ;
}
void F_12 ( T_1 * V_2 )
{
F_5 ( F_11 ( V_2 ) , L_5 ) ;
}
bool F_13 ( T_1 * V_2 )
{
int V_4 = 1 ;
return F_10 ( & V_2 -> V_5 , & V_4 , 0 ) ;
}
bool F_14 ( T_1 * V_2 )
{
unsigned int V_3 , V_4 = F_2 ( & V_2 -> V_5 ) ;
do {
if ( F_3 ( V_4 == V_6 ) )
return true ;
if ( V_4 == 1 )
return false ;
V_3 = V_4 - 1 ;
if ( V_3 > V_4 ) {
F_5 ( V_3 > V_4 , L_4 ) ;
return true ;
}
} while ( ! F_10 ( & V_2 -> V_5 , & V_4 , V_3 ) );
return true ;
}
bool F_15 ( T_1 * V_2 , struct V_7 * V_8 )
{
if ( F_14 ( V_2 ) )
return false ;
F_16 ( V_8 ) ;
if ( ! F_11 ( V_2 ) ) {
F_17 ( V_8 ) ;
return false ;
}
return true ;
}
bool F_18 ( T_1 * V_2 , T_2 * V_8 )
{
if ( F_14 ( V_2 ) )
return false ;
F_19 ( V_8 ) ;
if ( ! F_11 ( V_2 ) ) {
F_20 ( V_8 ) ;
return false ;
}
return true ;
}
